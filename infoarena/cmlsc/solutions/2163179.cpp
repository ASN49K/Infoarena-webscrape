#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("cmlsc.in");
    int M, N, x=0, X=0;
    f >> M >> N;
    int A[M], B[N];
    for(int i=0;i<M;i++)
    {
        f >> A[i];
    }
    for(int i=0;i<N;i++)
    {
        f >> B[i];
    }
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
            {
                if (A[i]==B[j]){x++;}
            }
    }
    f.close();

    ofstream o("cmlsc.out");
    int *C = new int [x]();
    o << x << "\n";
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(A[i]==B[j]){C[X++]=A[i];}
        }
    }

    for (int i=0;i<x;i++)
        {
            o << C[i] << " ";
        }
    o.close();
    delete []C;
}
