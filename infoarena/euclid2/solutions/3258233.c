#include <stdio.h>
#include <stdlib.h>
int cmmdc(int a,int b)
{
    int schimbdhaine;
    if(a>b){
        schimbdhaine=a;
        a=b;
        b=schimbdhaine;
    }

    if(b%a==0){
        return a;
    }
/*
        int a,b,t,d;
        scanf("%d",&t);

        if(b%a==0)
        {
            return a;
        }
        int d=a/2;
        while(d>=1)
        {
            if(a%d==0&&b%d==0)
            {
                return d;
            }
            d--;
    */

        while(b!=0){
            int r=a%b;
            a=b;
            b=r;
        }
        return a;

    }


    int main() {

    FILE*r,*w;
    r=fopen("euclid2.in", "r");
    w=fopen("euclid2.out", "w");
    int n,a,b,i;
    fscanf(r,"%d", &n);
    for(i=0;i<n;i++)
    {
        fscanf(r,"%d%d", &a, &b);
        fprintf(w,"%d\n", cmmdc(a,b));
    }
    }

//fml
