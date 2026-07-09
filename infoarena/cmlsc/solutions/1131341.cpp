#include <iostream>
#include <fstream>

using namespace std;

short int M,N;

short int m(short int a,short int b)
{
    if (a>=b) return a;
    return b;
}

int main()
{
    short int v1[M],v2[N],v3[m(M,N)],k=0,i,j,p=0;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>M>>N;
    for (i=0;i<M;i++)
    {
        f>>v1[i];
    }
    for (j=0;j<N;j++)
    {
        f>>v2[j];
    }
    for (i=0;i<M;i++)
    {
        for (j=0;j<N;j++)
        {
            if (v1[i]==v2[j])
            {
                if (p==0)
                {
                    v3[p]=v1[i];
                    p++;
                    k++;
                }
                else if (v1[i]>v3[p-1])
                {
                    v3[p]=v1[i];
                    p++;
                    k++;
                }
            }
        }
    }
    g<<k<<"\n";
    for (p=0;p<k;p++)
    {
        g<<v3[p]<<" ";
    }
    f.close(),g.close();
    return 0;
}
