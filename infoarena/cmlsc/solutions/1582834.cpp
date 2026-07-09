#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");\

int M,N;
int A[256], B[256], x[300];

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

void show()
{
    for(int i=0;i<M;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    for(int j=0;j<N;j++)
    {
        cout<<B[j]<<" ";
    }
}

int maxim (int x, int y)
{
    if(x>y)
        return x;
    return y;
}

void subsir()
{
    int k=0,cont=0;
    for(int i = 0; i< M; i++ )
    {
        for(int j = 0; j < N; j++)
        {
            if(A[i]==B[j])
            {
                x[k]=A[i];
                k++;
                cont++;
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        fout<<x[i]<<" ";
    }
    fout<<cont;
}

int main()
{
    read();
    show();
    subsir();
    return 0;
}
