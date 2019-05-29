#include <stdio.h>
#include <stdlib.h>
int main()
{
    int w,i;
    char p[20];

    printf("wiek: ");
    scanf("%d", &w);

    printf("plec: ");
    fflush(stdin);
    fgets(p,20,stdin);

    if("%s"=="dzieci", p)
    {
        if(w>=1 && w<=3)
            printf("1300");
        if(w>=4 && w<=6)
            printf("1700");
        if(w>=7 && w<=9)
            printf("2100");
    }
    else if("%s"=="mezczyzna", p)
    {
        if(w>=10 && w<=12)
            printf("2600m");
        if(w>=13 && w<=15)
            printf("3000-3300m");
        if(w>=16 && w<=20)
            printf("3200-3700m");
        if(w>=21 && w<=64)
            printf("2800-3200m");
        if(w>=65 && w<=75)
            printf("2300m");
        if(w>75)
            printf("2100m");
    }
    else if("%s"=="kobieta", p)
    {
        if(w>=10 && w<=12)
            printf("2300");
        if(w>=13 && w<=15)
            printf("2600-2800");
        if(w>=16 && w<=20)
            printf("2500-2700");
        if(w>=21 && w<=59)
            printf("2400-2800");
        if(w>=60 && w<=75)
            printf("2200");
        if(w>75)
            printf("2000");
    }
    else
        printf("Error");

    return 0;
}
