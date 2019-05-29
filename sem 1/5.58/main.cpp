 #include <stdio.h>
 #include <stdlib.h>
 #define N 1000

 int main()
 {
     int i,a=0;
     char tab[N],dlw[N];

     printf("wprowadz zdanie:\n");

     fgets(tab,N,stdin);

     for(i=0;tab[i]!=0;i++)
     {
         if(tab[i]>='a' && tab[i]<='z')
            a++;
         else if(tab[i]>='A' && tab[i]<='Z')
            a++;
         else if(tab[i]==' ')
            a++;
     }

     int b=0;
     for(i=0;i<a;i++)
     {
         if(tab[i]>='a' && tab[i]<='z')
         {
             dlw[b]+=1;
         }
         else if(tab[i]>='A' && tab[i]<='Z')
         {
             dlw[b]+=1;
         }
         else if(tab[i]==' ')
            b++;
     }

     for(i=0;i<b;i++)
     {

     }


     return 0;
 }
