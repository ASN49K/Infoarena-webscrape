#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    short int M,N;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>M>>N;
    short int v1[M],v2[N],v3[1024],k=0,i,j,p=0;

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
                v3[p]=v1[i];
                p++;
                k=k+1;
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
