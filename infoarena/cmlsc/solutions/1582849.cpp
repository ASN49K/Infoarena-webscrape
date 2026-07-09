#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");\

int M,N;
int A[1025], B[1025], x[1025];

void read ()
{
    fin>>M;
    fin>>N;
    for(int i = 0; i < M;i++)
    {
        fin>>A[i];
    }
    for(int j = 0; j < N; j++)
    {
        fin>>B[j];
    }
}


void subsir()
{
    int k=0;
    for(int i = 0; i< M; i++ )
    {
        for(int j = 0; j < N; j++)
        {
            if(A[i]<=256 && B[j]<=256)
            {
                 if(A[i]==B[j])
                {
                    x[k]=A[i];
                    k++;
                }
            }
        }
    }
    fout<<k<<"\n";
    for(int i=0;i<k;i++)
    {
        fout<<x[i]<<" ";
    }

}

int main()
{
    read();
    subsir();
    return 0;
}
