
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int method_select( void );
void print_result( double a, double b, unsigned int n, double I );
double f(double x);
double left_rectangular_metod( double a, double b, unsigned int n );
double right_rectangular_metod( double a, double b, unsigned int n );
double trap_metod( double a, double b, unsigned int n );
double simps_metod( double a, double b, unsigned int n );

double eps = 0.00001;

int main()

{

    unsigned int num_of_method;
    const double a=1;
    const double b=3;
    unsigned int n = 1000;
    double I;
    double I1, I2;
    unsigned int N;

    num_of_method = method_select();
    if(num_of_method==1)

    {
        system("cls");
    printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    printf("\n^         Result          ^");
    printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^");
       for (n = 100; n <= 10000; n = n * 10)

       {
        I = left_rectangular_metod(a, b, n);
        print_result(a, b, n, I);
       }

        N = 0;
        do{
        N = N + 2;
        I1 = left_rectangular_metod(a, b, N);
        I2 = left_rectangular_metod(a, b, N+2);

        }while(fabs(I2-I1)>eps);
        print_result(a, b, N, I2);

    }

    else if (num_of_method==2)

    {
        system("cls");
        printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^");
        printf("\n^         Result          ^");
        printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^");
       for (n = 100; n <= 10000; n = n * 10)

       {
        I = right_rectangular_metod(a, b, n);
        print_result(a, b, n, I);
       }

        N = 0;
        do{
        N = N + 2;
        I1 = right_rectangular_metod(a, b, N);
        I2 = right_rectangular_metod(a, b, N+2);
        }while(fabs(I2-I1)>eps);

        print_result(a, b, N, I2);
    }
    else if (num_of_method==3)
    {
        system("cls");
        printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^");
        printf("\n^         Result          ^");
        printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^");
       for (n = 100; n <= 10000; n = n * 10)
       {
        I = trap_metod(a, b, n);
        print_result(a, b, n, I);
       }
        N = 0;
        do{
        N = N + 2;
        I1 = trap_metod(a, b, N);
        I2 = trap_metod(a, b, N+2);
        }while(fabs(I2-I1)>eps);
        print_result(a, b, N, I2);
    }
    else if (num_of_method==4)
    {
        system("cls");
        printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^");
        printf("\n^         Result          ^");
        printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^");
       for (n = 100; n <= 10000; n = n * 10)
       {
        I = simps_metod(a, b, n);
        print_result(a, b, n, I);
       }
        N = 0;
        do{
        N = N + 2;
        I1 = simps_metod(a, b, N);
        I2 = simps_metod(a, b, N+2);
        }while(fabs(I2-I1)>eps);
        print_result(a, b, N, I2);
    }
    return 0;
}
//---------------------------------------------------------
unsigned int method_select(void)
{
   unsigned int metod;
   printf("\nEnter your metod:\n1 - Left rectangular metod \n2 - Right rectangular metod \n3 - Trap metod \n4 - Simpson metod \n> ");
   scanf("%u", &metod);
   while (metod != 1 && metod != 2 && metod != 3 && metod != 4)
{
  printf("\nError. Wrong metod. Enter metod again 1, 2, 3, or 4: ");
    scanf("%u", &metod);
}
switch(metod)
{
    case 1:
     printf("\n Method of left rectangles");
     break;
    case 2:
     printf("\n Method of right rectangles");
     break;
    case 3:
     printf("\n Method of trapezium");
     break;
    case 4:
     printf("\n Method of parabola");
     break;
}
return metod;
}
//---------------------------------------------------------
double left_rectangular_metod(double a, double b, unsigned int n)
{
    double h;
    unsigned int k;
    double x;
    double sum = 0;
    h =( b - a ) / n;
    x = a;
    for(k = 0; k <= (n-1); k++)
    {
        sum = sum + f(x);
        x = x + h;
    }

    return sum *

h;

}
//---------------------------------------------------------

double right_rectangular_metod(double a, double b, unsigned int n)
{
    double h;
    unsigned int k;
    double x;
    double sum = 0;
    h = ( b - a ) / n;
    x = a;
    for(k = 1; k <= n; k++)
    {
        sum = sum + f(x);
        x = x + h;
    }
    return sum * h;
}
//---------------------------------------------------------
double trap_metod(double a, double b, unsigned int n)
{
    double h;
    unsigned int k;
    double x1;
    double x2;
    double sum = 0;
    h = ( b - a ) / n;
    x1 = 0;
    x2 = a;
    for (k = 0; k <= (n-1); k++ )
    {
        sum = sum + (f(x1)+f(x2))/2;
        x1 = x2;
        x2 = x2 + h;
    }
    return sum*h;

}
//---------------------------------------------------------

double simps_metod(double a, double b, unsigned int n)
{
    double h;
    unsigned int k;
    double x;
    double sum = 0;
    h = ( b - a ) / n;
    x = a;
    for (k = 0; k <= n; k++ ) {
    if(k%2==1&&k<= (n-2))
        {
            sum = sum  + 2*f(x);
        }
        else if(k==n)
        {
            sum = sum + f(x);
        }
        else
        {
            sum = sum + 4*f(x);
        }
        x = x + h;
    }
    return(h/3*sum);
}
//---------------------------------------------------------
void print_result(double a, double b, unsigned int n, double I)
{
    printf("\na = %.2lf b = %.2lf n = %u I = %.8lf\n", a, b, n, I);
}
//---------------------------------------------------------
double f(double x)
{
    double y;
    y = sqrt(x + 1);
    return y;
}

