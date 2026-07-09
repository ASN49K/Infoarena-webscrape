#include <iostream>
#include <fstream>

using namespace std;

void Vector(int  V[],int v[], int K,int k, int X)
{
    int x=0;
    ofstream o("cmlsc.out");
    int *C = new int [X]();
    o << X << "\n";
    for(int i=0;i<K;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(V[i]==v[j]){C[x++]=V[i];}
        }
    }

    for (int i=0;i<X;i++)
        {
            o << C[i] << " ";
        }
    o.close();
    delete []C;
}

int main()
{
    ifstream f("cmlsc.in");
    int M, N, x=0;
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
    Vector(A,B,M,N,x);
}
