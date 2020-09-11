#include <stdio.h>
#include <math.h>

/*Greeting*/
void greetingsq()
{
    printf("Hi! This is QuadrEq v 1.0\n"
          "(c) TheRedHotHabanero\n"
          "It can solve your quadratic equations\n");
}

/*Input function*/
void inputsq(float *pa,float *pb, float *pc)
{
    printf("Write equation coefficients in oder: a, b, c.\n");
    scanf("%f%f%f", pa, pb, pc);

}

/*Output function*/
void output(int solutions, float ans1, float ans2)
{
    if (solutions == 1)
    {
        printf("Number of solutions of the equation: %d\n", solutions);
        printf("x = %g", ans1);
    }
    else if (solutions == 0)
        printf("Equation has no solutions");
    else if (solutions == 2)
    {
        printf("Number of solutions of the equation: %d\n", solutions);
        printf("x1 = %g, x2 = %g", ans1, ans2);
    }
    else
    {
        printf ("The number of solutions to the equation is infinite\n");
    }

}

/*Linear equation solution function*/
int LineEq(float a, float b, float* pans1)
{
    int solutions;
    if (a != 0)
    {
        *pans1 = -b / a;
        solutions = 1;
    }
    else if (a == 0 && b != 0)
        solutions = 0;
    else if (a == 0 && b == 0)
        solutions = -1;

    return (solutions);
}

/*Quadratic equation solution function*/
int QuadrEq(float a, float b, float c, float* pans1, float* pans2)
{
    int solutions;
    float D;

    if (a != 0)
    {
        D = b*b - 4*a*c;
        float sqroot;
        if (D == 0)
        {
            *pans1 = -b/(2*a);
            solutions = 1;
        }
       else if (D > 0)
        {
           sqroot = sqrt(D);
           *pans1 = (-b + sqroot)/(2*a);
           *pans2 = (-b - sqroot)/(2*a);
           solutions = 2;
        }
       else
           solutions = 0;
    }
    else
        solutions = LineEq(b, c, pans1);

    return (solutions);
}

int main()
{
    /*Introducing variables*/
    float a = 0, b = 0, c = 0;
    float ans1 = 0, ans2 = 0;
    int solnum = -1;
    float *pa, *pb, *pc, *pans1, *pans2;
    pa = &a; pb = &b; pc = &c;
    pans1 = &ans1; pans2 = &ans2;

    /*Functions call*/
    greetingsq();
    inputsq(pa, pb, pc);
    solnum = QuadrEq(a, b, c, pans1, pans2);
    output(solnum, ans1, ans2);

    return (0);

}
