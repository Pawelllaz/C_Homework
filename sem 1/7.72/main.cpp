#include <stdio.h>

double km2nm(double distance)
{
    double m;
    m=1.609344;
    return distance/m;
}
//-------------------------------
double km2lm(double distance)
{
    double m;
    m=1.851852;
    return distance/m;
}
//-------------------------------

int main()
{
    double dis;

    printf("wprowadz odleglosc (w km): ");
    scanf("%lf", &dis);
    printf("%.3lf mile morskie\n%.3lf mile ladowe", km2lm(dis), km2nm(dis));
    return 0;
}
