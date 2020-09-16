#include <stdio.h>
#include <math.h>

#define ONE_ROOT   1
#define NO_ROOTS   0
#define TWO_ROOTS  2
#define INF_ROOTS -1

/*Greeting*/
void greetingsq()
{
    printf("Hi! This is QuadrEq v 1.0\n"
          "(c) TheRedHotHabanero\n"
          "Solve your quadratic equations!\n");
}

/*Input function*/
void inputsq(double* pa, double* pb, double* pc)
{
    printf("Write equation coefficients in oder a, b, c: ");
    scanf("%lf%lf%lf", pa, pb, pc);
}

/*Output function*/
void output(int solutions, double ans1, double ans2)
{
    if (solutions == ONE_ROOT)
    {
        printf("Number of solutions of the equation: %d\n", solutions);
        printf("x = %lf", ans1);
    }
    else if (solutions == NO_ROOTS)
        printf("Equation has no solutions");
    else if (solutions == TWO_ROOTS)
    {
        printf("Number of solutions of the equation: %d\n", solutions);
        printf("x1 = %lf, x2 = %lf", ans1, ans2);
    }
    else
        printf ("The number of solutions to the equation is infinite\n");

}

/*Linear equation solution function*/
int LineEq(double a, double b, double* pans1)
{
    int solutions;
    if (a != 0)
    {
        *pans1 = -b / a;
        solutions = ONE_ROOT;
    }
    else if (a == 0 && b != 0)
        solutions = NO_ROOTS;
    else if (a == 0 && b == 0)
        solutions = INF_ROOTS;

    return (solutions);
}

/*Quadratic equation solution function*/
int QuadrEq(double a, double b, double c, double* pans1, double* pans2)
{
    int solutions;
    double D;

    if (a != 0)
    {
        D = b*b - 4*a*c;
        double sqroot;
        if (D != 0)
        {
            if (D > 0)
            {
                sqroot = sqrt(D);
                *pans1 = (-b + sqroot) / (2 * a);
                *pans2 = (-b - sqroot) / (2 * a);
                solutions = TWO_ROOTS;
            }
            else
                solutions = NO_ROOTS;
        }
        else
        {
            *pans1 = -b / (2 * a);
            solutions = ONE_ROOT;
        }


    }
    else
        solutions = LineEq(b, c, pans1);

    return (solutions);
}

/*Checking the program*/
void QuadrEqTests()
{
    printf("\n\n\nTime to check the program!\n\n");

    int results = 0; int lenmas = 6;
    double root1 = 0, root2 = 0;

    double masA[] =   { 1,  1,  1,  0, 0, 0};
    double masB[] =   {-2, -4, -2,  0, 1, 0};
    double masC[] =   {-3,  4,  4,  0, 2, 7};
    double masRes[] = { 2,  1,  0, -1, 1, 0};

    for (int k = 0; k <= lenmas -1; k++)
    {
        results = QuadrEq(masA[k], masB[k], masC[k], &root1, &root2);
        if (results == masRes[k])
            printf("Test %d Passed \n", (k+1));
        else
            printf("Test 1 BAD: solutions = %lf expected, "
                   "but solutions = %d given\n", masRes[k], results);
    }
}

int main()
{
    /*Introducing variables*/
    double a = 0, b = 0, c = 0;
    double ans1 = 0, ans2 = 0;
    int solnum = -1;


    /*Functions call*/
    greetingsq();
    inputsq(&a, &b, &c);
    solnum = QuadrEq(a, b, c, &ans1, &ans2);
    output(solnum, ans1, ans2);
    //QuadrEqTests();

    return (0);

}
