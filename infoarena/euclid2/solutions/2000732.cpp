#include<cstdio>
using namespace std;

int Euclid(int a, int b)
{
    int r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int T, x, y, i;
    FILE *fin, *fout;
    fin = fopen("euclid2.in","r");
    fout = fopen("euclid2.out","w");
    fscanf(fin,"%d",&T);
    for(i=0; i<T; i++)
    {
        fscanf(fin,"%d%d",&x,&y);
        fprintf(fout,"%d\n",Euclid(x,y));
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
