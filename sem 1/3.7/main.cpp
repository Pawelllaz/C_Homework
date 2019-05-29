#include <stdio.h>
#include <stdlib.h>

int main()
{
    float z,eu=4.2074,funt=4.7073,dol=3.5382;
    char znak;

    printf("podaj kwote w zlotowkach: ");
    scanf("%f", &z);
    printf("na jaka walute chcesz konwertowac pieniadze ? (d-dolary f-funty e-euro\n");
    fflush(stdin);
    scanf("%c", &znak);

    switch (znak)
    {
    case 'f':
        printf("%.2f", z*funt);
        break;
    case 'd':
        printf("%.2f", z*dol);
        break;
    case 'e':
        printf("%.2f", z*eu);
        break;
    }



    return 0;
}
