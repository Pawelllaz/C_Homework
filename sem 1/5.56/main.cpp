#include <stdio.h>
#include <stdlib.h>
#define N 1000

int main()
{
    char tab[N];
    int i,il[N],a;


    printf("wpisz tekst:\n");

    fgets(tab,N,stdin);

    a=0;
    for(i=0;tab[i+1]!=0;i++)
    {
        if(tab[i]>=65 && tab[i]<=90)
        {
            a++;
        }
        else if(tab[i]>=97 && tab[i]<=122)
        {
            a++;
        }
        else if(tab[i]==' ')
        {
            a++;
        }
    }

    char licz[]="abcdefghijklmnopqrstuvwxyz";
    for(i=0;i<N;i++)
        il[i]=0;
    for(i=0;i<a;i++)
    {
        switch (tab[i])
        {
        case 'a':
            il[0]+=1;
            break;
        case 'A':
            il[0]+=1;
            break;
        case 'b':
            il[1]+=1;
            break;
        case 'B':
            il[1]+=1;
            break;
        case 'c':
            il[2]+=1;
            break;
        case 'C':
            il[2]+=1;
            break;
        case 'd':
            il[3]+=1;
            break;
        case 'D':
            il[3]+=1;
            break;
        case 'E':
            il[4]+=1;
            break;
        case 'e':
            il[4]+=1;
            break;
        case 'f':
            il[5]+=1;
            break;
        case 'F':
            il[5]+=1;
            break;
        case 'g':
            il[6]+=1;
            break;
        case 'G':
            il[6]+=1;
            break;
        case 'h':
            il[7]+=1;
            break;
        case 'H':
            il[7]+=1;
            break;
        case 'i':
            il[8]+=1;
            break;
        case 'I':
            il[8]+=1;
            break;
        case 'j':
            il[9]+=1;
            break;
        case 'J':
            il[9]+=1;
            break;
        case 'k':
            il[10]+=1;
            break;
        case 'K':
            il[10]+=1;
            break;
        case 'l':
            il[11]+=1;
            break;
        case 'L':
            il[11]+=1;
            break;
        case 'm':
            il[12]+=1;
            break;
        case 'M':
            il[12]+=1;
            break;
        case 'N':
            il[13]+=1;
            break;
        case 'n':
            il[13]+=1;
            break;
        case 'O':
            il[14]+=1;
            break;
        case 'o':
            il[14]+=1;
            break;
        case 'P':
            il[15]+=1;
            break;
        case 'p':
            il[15]+=1;
            break;
        case 'Q':
            il[16]+=1;
            break;
        case 'q':
            il[16]+=1;
            break;
        case 'R':
            il[17]+=1;
            break;
        case 'r':
            il[17]+=1;
            break;
        case 'S':
            il[18]+=1;
            break;
        case 's':
            il[18]+=1;
            break;
        case 'T':
            il[19]+=1;
            break;
        case 't':
            il[19]+=1;
            break;
        case 'U':
            il[20]+=1;
            break;
        case 'u':
            il[20]+=1;
            break;
        case 'V':
            il[21]+=1;
            break;
        case 'v':
            il[21]+=1;
            break;
        case 'W':
            il[22]+=1;
            break;
        case 'w':
            il[22]+=1;
            break;
        case 'X':
            il[23]+=1;
            break;
        case 'x':
            il[23]+=1;
            break;
        case 'Y':
            il[24]+=1;
            break;
        case 'y':
            il[24]+=1;
            break;
        case 'Z':
            il[25]+=1;
            break;
        case 'z':
            il[25]+=1;
            break;
        }
    }
    for(i=0;i<=25;i++)
        printf("%c - %d\n", licz[i],il[i]);

    return 0;
}
