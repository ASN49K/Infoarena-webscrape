#include <iostream>
#include <fstream>

using namespace std;

#define LMAX 1025
int main()
{
    int m,n;
    ifstream f("cmlsc.in");

    ofstream g("cmlsc.out");
    int A[LMAX],B[LMAX];
    f>>m>>n;
    for(int i=1;i<=m;i++)
        f>>A[i];
    for(int i=1;i<=n;i++)
        f>>B[i];
    f.close();
    int k=0,smax,sfinal=0,aux,V[LMAX],r,rf,VF[LMAX];
    while(k<m-1)
    {
        ++k;
        smax=0;
        aux=0;
        r=0;
        for(int i=k;i<=m;++i)
            for(int j=1;j<=n;++j)
                if((A[i]==B[j])&&(j>aux))
                {
                    smax++;
                    aux=j;
                    r++;
                    V[r]=A[i];
                    break;
                }
        if(smax>sfinal)
        {
            sfinal=smax;
            for(int i=1;i<=r;++i)
                VF[i]=V[i];
            rf=r;
        }
    }
    g<<sfinal<<"\n";
    for(int i=1;i<=rf;++i)
        g<<VF[i]<<" ";
    g.close();
    return 0;
}
