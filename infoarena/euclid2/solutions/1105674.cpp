#include <cstdio>

using namespace std;

FILE* fin=fopen("euclid2.in","r");
FILE* fout=fopen("euclid2.out","w");
int cmmdc(int a, int b);

int main()
{
    int T,a,b;
    fscanf(fin,"%d",&T);
    for(int k=1;k<=T;k++)
    {
        fscanf(fin,"%d %d",&a,&b);
        fprintf(fout,"%d\n",cmmdc(a,b));
    }
    return 0;
}

int cmmdc(int a, int b)
{

    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;

}
