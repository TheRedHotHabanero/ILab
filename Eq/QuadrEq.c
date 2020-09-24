#include <stdio.h>
#include <math.h>
#include <assert.h>

#define ONE_ROOT   1
#define NO_ROOTS   0
#define TWO_ROOTS  2
#define INF_ROOTS -1

#define FAULT      1e-6

//================================================================================
// Greeting function!
// @note Returns nothing, it`s just for smile
//---------------------------------------------------------------
void greetingsq()
{
    printf(  "Hi! This is QuadrEq v 2.0\n"
                    "(c) TheRedHotHabanero\n"
                    "Solve your quadratic equations!\n" );
}
//================================================================================

//================================================================================
// Here is input function. The first and the last place
// where you communicate with user.
// It can "eat" your coefficients of the equation, be careful.
// @param [out] pa, pb, pc - paths to a, b, c coefficients.
//---------------------------------------------------------------
void inputsq(double* pa, double* pb, double* pc)
{
    printf("Write equation coefficients in oder a, b, c: ");
    scanf("%lf%lf%lf", pa, pb, pc);
    printf("\n");
}
//================================================================================


//================================================================================
// Zero_is_zero function. It checks the faults of a close to zero numbers.
// Zero_is_zer returns 0 if the number is too close to zero
// and return 1 in the opposite situation.
// @param [in] n  - a number that should be transfered to function and checked.
//---------------------------------------------------------------
int zero_is_zero(double n)
{
    if ( fabs(n) < FAULT )
        return 0;
    return 1;
}
//================================================================================


//================================================================================
// Output function. It is to show the results of QuadrEq function.
// Just print out, returns nothing.
// Output function try to make user happier...
// @param [in] solutions - amount of solutions
// @param [in] ans1      - the first root
// @param [in] ans2      - the second root (in case it exists)
//---------------------------------------------------------------
void output(int solutions, double ans1, double ans2)
{
    printf("------------------------------------------------------\n");
    switch (solutions)
    {
        case ONE_ROOT:  printf("-- Number of solutions of the equation: %d\n", solutions);
                        printf("-- x = %lf ", ans1);
                        break;

        case NO_ROOTS:  printf("-- Equation has no solutions");
                        break;

        case TWO_ROOTS: printf("-- Number of solutions of the equation: %d\n", solutions);
                        printf("-- x1 = %lf, x2 = %lf", ans1, ans2);
                        break;

        case INF_ROOTS: printf ("-- The number of solutions to the equation is infinite\n");
                        break;

        default:        printf("-- Error: solutions, QuadrEq");
                        break;

    }
    printf("\n------------------------------------------------------");
}
//================================================================================

//================================================================================
// Linear equation solution function.
int LineEq(double a, double b, double* pans1)
{
    assert(isfinite(a) && isfinite(b));

    int solutions;

    if (zero_is_zero(a) * a != 0)
        {
            *pans1 = -b / a;
            solutions = ONE_ROOT;
        }
    else if (zero_is_zero(b) * b != 0)
            solutions = NO_ROOTS;
    else
            solutions = INF_ROOTS;

    return (solutions);
}

/*Quadratic equation solution function*/
int QuadrEq(double a, double b, double c, double* pans1, double* pans2)
{
    assert(isfinite(a) && isfinite(b) && isfinite(c));

    int solutions;

    if (zero_is_zero(a) * a == 0)
        {
            solutions = LineEq(b, c, pans1);
            return solutions;
        }

    double d = b*b - 4*a*c;             //discriminant without fault
    double D = zero_is_zero(d) * d;     //working discriminant
    double sqroot = sqrt(D);

    if (D > 0)
        {
            *pans1 = (-b + sqroot) / (2 * a);
            *pans2 = (-b - sqroot) / (2 * a);
            solutions = TWO_ROOTS;
        }
    else if (D == 0)
        {
            *pans1 = -b / (2 * a);
            solutions = ONE_ROOT;
        }
    else if (D < 0)
            solutions = NO_ROOTS;

    return (solutions);
}

/*Checking the program*/
void QuadrEqTests()
{


    printf("\n\n\nTime to check the program!\n\n");

    int results, lenmas = 6;
    double root1 = NAN, root2 = NAN;


    //--TEST----------------------1---2---3---4---5---6---
    double masA[]           =   { 1,  1,  0,  0,  0,  1};
    double masB[]           =   {-4, -2,  0,  1,  0, -2};
    double masC[]           =   { 4,  4,  0,  2,  7, -3};
    double masResNumSol[]   =   { 1,  0, -1,  1,  0,  2};
    double masResRoots[]    =   { 2,  0,  0, -2,  0,  2};

    for (int k = 0; k <= lenmas -1; k++)
    {
        results = QuadrEq(masA[k], masB[k], masC[k], &root1, &root2);

        if (results != masResNumSol[k])
            {
                printf("Test %d BAD, wrong solutions amount. \n", k+1);
                continue;
            }

        switch (results)
            {
                case NO_ROOTS:      printf("Test %d Passed \n", (k+1));
                                    break;

                case INF_ROOTS:     printf("Test %d Passed \n", (k+1));
                                    break;

                case ONE_ROOT:      if (root1 * 1.0 == masResRoots[k])
                                            printf("Test %d Passed \n", (k + 1));
                                    else
                                            printf("Test %d BAD, wrong root\n", k+1);
                                    break;

                case TWO_ROOTS:     if ((root1 + root2) * 1.0 == masResRoots[k])
                                            printf("Test %d Passed \n", (k + 1));
                                    else
                                            printf("Test %d BAD, wrong roots. \n", k+1);
                                    break;

                default:            printf ("Error: QuadrEqTest");
            }
    }
}

int main()
{
    /*Introducing variables*/
    double a = NAN, b = NAN, c = NAN;
    double ans1 = NAN, ans2 = NAN;
    int solnum;


    /*Functions call*/
    greetingsq();
    inputsq(&a, &b, &c);
    solnum = QuadrEq(a, b, c, &ans1, &ans2);
    output(solnum, ans1, ans2);
    //QuadrEqTests();

    return (0);

}
