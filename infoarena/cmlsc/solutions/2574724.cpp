#include<fstream>
using namespace std;
int main ()
{
    fstream f("cmlsc.in",ios::in), g("cmlsc.out",ios::out);
    unsigned short int M,N,A[1024],B,k=0,i,j,nr=0,nrmax[256];
    f>>M>>N;
    for (i=0;i<M;i++)
    {
        f>>A[i];
    }
    for (i=0;i<N;i++)
    {
        f>>B;
        j=k;
        while(j<M && B!=A[j])
            ++j;

        if (j<M)
              {
                nrmax[nr]=B;
                ++nr;
                k=j+1;
              }
        }

      g<<nr<<"\n";
    for (i=0;i<nr;i++)
    {
            g<<nrmax[i]<<" ";
    }

    return 0;
}
