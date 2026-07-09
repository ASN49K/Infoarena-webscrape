#include <iostream>
#include <fstream>
using namespace std;
int i1,nn,n,r,nr,i;
int main(void)
{
    FILE * f;
    f=fopen("nim.in","r");
    ofstream g("nim.out");
    fscanf(f,"%d",&nn);
    for (i1=1;i1<=nn;i1++)
    {
        fscanf(f,"%d",&n);
        r=0;
        for (i=1;i<=n;i++)
        {
            fscanf(f,"%d",&nr);
            r=r^nr;
        }
        if (r==0)
            g<<"NU\n";
        else
            g<<"DA\n";
    }
    g.close();
    return 0;
}
