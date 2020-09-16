#include <stdio.h>
#include <math.h>

/*Greeting*/
void greetingsq()
{
    printf("Hi! This is QuadrEq v 1.0\n"
          "(c) TheRedHotHabanero\n"
          "Solve your quadratic equations!\n");
}

/*Input function*/
void inputsq(double* a, double* b, double* c)
{
    printf("Write equation coefficients in oder a, b, c: ");
    scanf("%lf%lf%lf", a, b, c);
}

/*Output function*/
void output(int solutions, double ans1, double ans2)
{
    if (solutions == 1)
    {
        printf("Number of solutions of the equation: %d\n", solutions);
        printf("x = %lf", ans1);
    }
    else if (solutions == 0)
        printf("Equation has no solutions");
    else if (solutions == 2)
    {
        printf("Number of solutions of the equation: %d\n", solutions);
        printf("x1 = %lf, x2 = %lf", ans1, ans2);
    }
    else
        printf ("The number of solutions to the equation is infinite\n");

}

/*Linear equation solution function*/
int LineEq(double a, double b, double* ans1)
{
    int solutions;
    if (a != 0)
    {
        *ans1 = -b / a;
        solutions = 1;
    }
    else if (a == 0 && b != 0)
        solutions = 0;
    else if (a == 0 && b == 0)
        solutions = -1;

    return (solutions);
}

/*Quadratic equation solution function*/
int QuadrEq(double a, double b, double c, double *ans1, double *ans2)
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
                *ans1 = (-b + sqroot) / (2 * a);
                *ans2 = (-b - sqroot) / (2 * a);
                solutions = 2;
            }
            else
                solutions = 0;
        }
        else
        {
            *ans1 = -b / (2 * a);
            solutions = 1;
        }


    }
    else
        solutions = LineEq(b, c, &ans1);

    return (solutions);
}

/*Checking the program*/
void QuadrEqTests()
{
    printf("\n\n\nTime to check the program!\n\n");

    int results = 0; int lenmas = 6;
    double root1 = 0, root2 = 0;

    double masA[] = {1, 1, 1, 0, 0, 0};
    double masB[] = {-2, -4, -2, 0, 1, 0};
    double masC[] = {-3, 4, 4, 0, 2, 7};
    double masRes[] = {2, 1, 0, -1, 1, 0};

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
