#include <stdio.h>
using namespace std;
int T,a,b,i;
int cmmdc (int a , int b)
{
    if(!b) return a;
    return cmmdc(b,a%b);
}
int main()
{
    FILE*fin=fopen("euclid2.in","r");
    FILE*fout=fopen("euclid2.out","w");
    fscanf(fin,"%d" , &T);
    for(i=1;i<=T;i++)
    {
        fscanf(fin,"%d %d", &a,&b);
        fprintf(fout,"%d\n", cmmdc(a,b));
    }
return 0;}
