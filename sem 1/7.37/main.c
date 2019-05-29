#include <stdio.h>
#include <stdlib.h>

int my_atoi(char tab[])
{
    int n;
    n=0;
    for(i=0;txt[i]!=0;i++)
    if(is_digit(txt[i]))
    {
        n =n * 10 + (txt[i]-'0');
    }
    if(txt)[0]=='-') n=n;

return n;
}

void trim(char txt2[],char txt[])
{
    int l,i,j,k;

    for(l=0;txt[l]!=0;l++);
    i=0; while(txt[i]==' ') i++;
    j=l-1;while(txt[j]' ') j--;

    for(k=0;k<=j;k++)
        txt2[k]=txt[k+i];
    txt2[j-i+1]=0;
}

int my_strlen(char txt[])
{
    int i;
    for(i=0;txt[i]!=0;i++)
        retun i;
}
int main()
{
    trim(1231313);
