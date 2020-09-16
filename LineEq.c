#include <stdio.h>

/*Greeting*/
void greetingline()
{
    printf("Hi! This is LineEq v 1.0\n"
           "(c) TheRedHotHabanero\n"
           "Solve your lineal equations!\n");
}

/*Intput function*/
float inputline(double* a, double* b)
{
    printf("Write equation coefficients in oder: a, b\n");
    scanf("%lf%lf", a, b);

}

/*Output function*/
void output(int solutions, double ans)
{
    if (solutions == 1)
    {
        printf("Number of solutions of the equation: %d\n", solutions);
        printf("x = %lf", ans);
    }
    else if (solutions == 0)
        printf("Equation has no solutions");
    else
        printf("The number of solutions to the equation is infinite");
}

/*Linear equation solution function*/
int LineEq(double a, double b, double* ans)
{
    int solutions;
    if (a != 0)
    {
        *ans = -b / a;
        solutions = 1;
    }
    else if (a == 0 && b != 0)
        solutions = 0;
    else if (a == 0 && b == 0)
        solutions = -1;

    return (solutions);
}

/*Checking the program*/
void LineEqTests()
{
    printf("\n\n\nTime to check the program!\n\n");

    int results = 0; int lenmas = 3;
    double root = 0;

    double masA[] = {0,1,0};
    double masB[] = {0,2,7};
    double masRes[] = {-1,1,0};

    for (int k = 0; k <= lenmas -1; k++)
    {
        results = LineEq(masA[k], masB[k], &root);
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
    double a = 0, b = 0, ans  = 0;
    int solnum = -1;

    /*Functions call*/
    greetingline();
    inputline(&a, &b);
    solnum = LineEq(a, b, &ans);
    output(solnum, ans);
    //LineEqTests();

    return (0);
}

