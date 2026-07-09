#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **args,char **envp)
{
    int a=0,b=0;
    fprintf(stdout,"Programul care calculeaza cmmdc-ul a doua numere intregi!\n");
    fprintf(stdout,"Introduceti o valoare pentru a: ");
    fscanf(stdin,"%d",&a);
    fprintf(stdout,"Introduceti o valoare pentru b: ");
    fscanf(stdin,"%d",&b);
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    fprintf(stdout,"Cmmdc-ul celor 2 numere introduse este %d.",a);
    return 0;
}
