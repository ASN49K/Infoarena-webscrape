#include <iostream>
#include <fstream>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
short int Tabel[1100][1100],N,M,a[1100],b[1100];
inline short int Maximul(short int a,short int b)
{
    if(a>=b) return a;
    else return b;
}
int ParcurgereTabel()
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
            Tabel[i][j]=Maximul(Tabel[i-1][j],Tabel[i][j-1]);

        }

    }
    return 0;
}
int ReconstruireVector()
{
    short int i,j,o=0, C[100];
    i=M;j=N;
    while(i && j)
    {
        if(a[i]==b[j])
        {
            C[o++]=a[i];
            i--;
            j--;
        }
        else
        {
            if(Tabel[i][j-1]>=Tabel[i-1][j])
            {
                j--;
            }
            else i--;
        }
    }
    out<<Tabel[M][N]<<'\n';
    for(int p=o-1;p>=0;p--)
    out<<C[p]<<" ";
    return 0;
}
int main()
{
    in>>M>>N;
    for(short int i=1;i<=M;i++)
    in>>a[i];
    for(short int j=1;j<=N;j++)
    in>>b[j];
    ParcurgereTabel();
    ReconstruireVector();
}
