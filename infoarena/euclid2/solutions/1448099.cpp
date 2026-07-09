#include <cstdio>

using namespace std;
FILE *fi,*fo;
int euclid(int a, int b)
{
    if(b==0)
        return a;
    return euclid(b,a%b);
}
int t,a,b;
int main()
{
    fi=fopen("euclid2.in","r");
    fo=fopen("euclid2.out","w");
    fscanf(fi,"%d",&t);
    for(int i = 1;i<=t;i++)
    {
        fscanf(fi,"%d%d",&a,&b);
        fprintf(fo,"%d\n",euclid(a,b));
    }
    fclose(fi);
    fclose(fo);
    return 0;
}
