#include <iostream>

using namespace std;
int Tabel[10][10];
int Maximul(int a,int b)
{
    if(a>=b) return a;
    else return b;
}
int ParcurgereTabel();
{
    for(int i=1;i<=M;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(a[i]==b[j])
            {
                Tabel[i][j]=Tabel[i-1][j-1]+1;
            }
            else
            Tabel[i][j]=Maximul(Tabel[i-1][j],Tabel[i][j-1])

        }

    }
}
int main()
{
    cin>>M>>N;
    for(int i=1;i<=M;i++)
    cin>>A[i];
    for(int i=1;i<=N;i++)
    cin>>B[i];
    for(int i=1;i<=M;i++)
    {
        for(int j=1;j<=N,j++)

    }
}
