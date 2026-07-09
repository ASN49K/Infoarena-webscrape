#include <stdio.h>

using namespace std;

int euclid(int a,int b)
{
    if(b==0)
        return a;
    return euclid(b,a%b);
}

int main()
{
    FILE *fin, *fout;

    fin=fopen("euclid2.in","r");
    fout=fopen("euclid2.out","w");

    int t;

    fscanf(fin,"%d",&t);

    for(int i=1;i<=t;i++)
    {
        int a,b;
        fscanf(fin,"%d%d",&a,&b);
        fprintf(fout,"%d\n",euclid(a,b));
    }

    return 0;
}
