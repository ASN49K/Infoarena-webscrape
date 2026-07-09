#include<fstream>
using namespace std;
int main ()
{
    fstream f("cmlsc.in",ios::in), g("cmlsc.out",ios::out);
    unsigned short int M,N,A[1024],B[1024],i,j,nr=0,nrmax[1024];
    f>>M>>N;
    for (i=0;i<M;i++)
    {
        f>>A[i];
    }
    for (i=0;i<N;i++)
    {
        f>>B[i];
        for (j=i;j<=M;j++)
        {
            if (B[i]==A[j])
              {
                ++nr;
                nrmax[i]=B[i];
              }
        }
    }
    g<<nr<<"\n";
    for (i=0;i<M;i++)
    {
        if (nrmax[i]!=0)
            g<<nrmax[i]<<" ";
    }





    return 0;
}
