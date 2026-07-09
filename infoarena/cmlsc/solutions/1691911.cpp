#include<iostream>
#include <fstream>

using namespace std;
ifstream f("cm1sc.in");
ofstream g("cm1sc.out");
void citire(int &n, int x[],int &m, int a[])
{
    f>>n;
    f>>m;
    for(int i=1; i<=n; i++)
    {
        f>>x[i];
    }
     for(int i=1; i<=m; i++)
    {
        f>>a[i];
    }
}
void verifica(int n,int A[],int m,int B[],int &k, int C[])
{
    C[1]=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(A[i]==B[j])
            {
                k++;
                C[k]=A[i];
                if(C[k]<C[k-1])
                    {k--;}
            }
        }
    }
}
void show(int n, int x[])
{
    g<<n-1<<endl;
    for(int i=2; i<=n; i++)
    {
        g<<x[i]<<" ";
    }
}
int main()
{
    int n, m, A[100],B[100],k=1,C[100];
    citire(n,A,m,B);
    verifica(n,A,m,B,k,C);
    show(k,C);


}
