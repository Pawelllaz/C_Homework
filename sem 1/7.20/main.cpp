#include <stdio.h>
#include <math.h>

float distance(int x1, int y1, int x2, int y2)
{
    float x,y,dlugosc;
    x = x2 - x1;
    y = y2 - y1;
    dlugosc = sqrt(x*x+y*y);
    return dlugosc;
}
//--------------------------------------------------------
float perimeter(float a, float b, float c)
{
    return a+b+c;
}
//--------------------------------------------------------
float area(float a, float b, float c)
{
    float p = (perimeter(a,b,c))/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
//--------------------------------------------------------
int main()
{
    float x1,x2,x3,y1,y2,y3;
    printf("podaj wspolrzedna x pierwszego punktu: ");
    scanf("%f", &x1);

    printf("podaj wspolrzedna y pierwszego punktu: ");
    scanf("%f", &y1);

    printf("podaj wspolrzedna x drugiego punktu: ");
    scanf("%f", &x2);

    printf("podaj wspolrzedna y drugiego punktu: ");
    scanf("%f", &y2);

    printf("podaj wspolrzedna x trzeciego punktu: ");
    scanf("%f", &x3);

    printf("podaj wspolrzedna y trzeciego punktu: ");
    scanf("%f", &y3);

    printf("%.2f", area(distance(x1,y1,x2,y2),distance(x1,y1,x3,y3),distance(x2,y2,x3,y3)));

    return 0;
}
