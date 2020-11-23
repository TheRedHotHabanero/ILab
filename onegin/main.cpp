#include <cassert>
#include <cstdlib>
#include <cstdio>

#include <cstring>

//const int size_name_file = 12;

struct Buffer
{
  char* data;
  size_t size;
};

struct Lines
{
  char** data;
  size_t lnum;
};

Buffer file_to_buf(char name[])
{
  Buffer buf = {nullptr, 0};

  FILE* fd = fopen(name, "r");
  assert(fd != nullptr);

  assert(fseek(fd, 0, SEEK_END) == 0); // сдвиг каретки в конец
  buf.size = ftell(fd) + 1; // узнаем положение каретки относительно начала файла
  assert(fseek(fd, 0, SEEK_SET) == 0);


  buf.data = (char*)calloc(buf.size, sizeof(char));

  fread(buf.data, sizeof(char), buf.size, fd);
  fclose(fd);

  return buf;
}

Lines create_line_array(Buffer buf)
{
  Lines lines = {nullptr, 1};

  for (int i = 0; i < buf.size; ++i)
    if (buf.data[i] == '\n')
      lines.lnum++;

  lines.data = (char**)calloc(lines.lnum, sizeof(char*));
  lines.data[0] = buf.data;

  int u = 1;

  for (int i = 0; i < buf.size; ++i)
    if (buf.data[i] == '\n' && i != buf.size - 1)
    {
      buf.data[i] = '\0';
      lines.data[u] = &buf.data[i + 1];
      ++u;
    }
  return lines;
}

int main()
{
  char name[100] = "../";

  printf("Input filename: ");
  scanf("%s", name + 3);

  Buffer buf = file_to_buf(name);
  Lines lines = create_line_array(buf);

  for (int i = 0; i < lines.lnum; ++i)
    printf("%s\n", lines.data[i]);

  free(buf.data);
  free(lines.data);
  return 0;
}
