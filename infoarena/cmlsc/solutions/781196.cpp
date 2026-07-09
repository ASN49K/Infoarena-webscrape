#include <iostream>
#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int nrA,nrB,i,j,A[500],B[500],v[500],maxx,a;
int main()
{
    fin>>nrA>>nrB;
    for(i=1;i<=nrA;i++)
    {
        fin>>A[i];
    }
    for(i=1;i<=nrB;i++)
    {
        fin>>B[i];
    }
    if(nrA>nrB)
    {
        for(i=1;i<=nrB;i++)
        {
            for(a=i;a<=nrA;a++)
            {
                if(B[i]==A[a])
                {
                    maxx++;j++;
                    v[j]=B[i];
                }
            }
        }
    }
    else
    {
       for(i=1;i<=nrA;i++)
        {
            for(a=i;a<=nrB;a++)
            {
                if(A[i]==B[a])
                {
                    maxx++;j++;
                    v[j]=A[i];
                }
            }
        }
    }
    fout<<maxx<<"\n";
    for(i=1;i<=j;i++)
        fout<<v[i]<<" ";

    return 0;
}
