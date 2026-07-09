#include<stdio.h>
using namespace std;
long int t,i;long long a,b,r;
int main()
{
    FILE*fin=fopen("euclid2.in","r");
    FILE*fout=fopen("euclid2.out","w");
    fscanf(fin,"%d",&t);
    for(i=1;i<=t;i++)
    {
        fscanf(fin,"%d %d",&a,&b);
        if(b>a){r=a;a=b;b=r;}
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fprintf(fout,"%d\n",a);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}


