#include<cstdio>
using namespace std;

int t, a, b;

int Euclid(int x, int y)
{
    int r;
    while(y)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    FILE *fin, *fout;
    fin = fopen("euclid2.in","r");
    fout = fopen("euclid2.out","w");
    fscanf(fin,"%d",&t);
    for(int i=1; i<=t; i++)
    {
        fscanf(fin,"%d%d",&a,&b);
        fprintf(fout,"%d\n",Euclid(a,b));
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
