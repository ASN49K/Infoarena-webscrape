#include <cstdio>
#include <fstream>

using namespace std;

int n,a,b,c;

int cmmdc(int m,int n)
{
    if(n==0)
        return m;
    if(m>n)
        return cmmdc(m-n,n);
    return cmmdc(m,n-m);

}

int main()
{
    fstream f("euclid2.in",ios::in);
    FILE *g=fopen("euclid2.out","w");
    f >> n;
    for(int i=0;i<n;i++)
    {
        f >> a >> b;
        c = cmmdc(a,b);
        fprintf(g,"%i\n",c);
    }
    return 0;
}
