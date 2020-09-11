#include <stdio.h>

/*Greeting*/
void greetingline()
{
    printf("Hi! This is LineEq v 1.0\n"
           "(c) TheRedHotHabanero\n"
           "It can solve your lineal equations\n");
}

/*Intput function*/
float inputline(float *pa, float *pb)
{
    printf("Write equation coefficients in oder: a, b\n");
    scanf("%f%f", pa, pb);

}

/*Output function*/
void output(int solutions, float ans)
{
    if (solutions == 1)
    {
        printf("Number of solutions of the equation: %d\n", solutions);
        printf("x = %g", ans);
    }
    else if (solutions == 0)
        printf("Equation has no solutions");
    else
        printf("The number of solutions to the equation is infinite");
}

/*Linear equation solution function*/
int LineEq(float a, float b, float* pans)
{
    int solutions;
    if (a != 0)
    {
        *pans = -b / a;
        solutions = 1;
    }
    else if (a == 0 && b != 0)
        solutions = 0;
    else if (a == 0 && b == 0)
        solutions = -1;

    return (solutions);
}

int main()
{
    /*Introducing variables*/
    float a = 0, b = 0, ans  = 0;
    int solnum = -1;
    float *pa, *pb, *pans;
    pa = &a, pb = &b, pans = &ans;

    /*Functions call*/
    greetingline();
    inputline(pa, pb);
    solnum = LineEq(a, b, pans);
    output(solnum, ans);

    return (0);
}

