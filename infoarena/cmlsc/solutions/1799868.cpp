#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int NMax=1028;

int t[1028][1028],n,m,A[1028],B[1028],s[1028],k;

void read()
{
    fin>>m>>n;
    for(int i=1;i<=m;++i)
    {
        fin>>A[i];
    }
     for(int i=1;i<=n;++i)
    {
        fin>>B[i];
    }
}

void sol()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(A[i]==B[j])
                t[i][j]=1+t[i-1][j-1];
            else t[i][j] = max(t[i-1][j],t[i][j-1]);
        }
    }

int i=m, j=n;
      fout<<t[m][n]<<'\n';
    while ((i>0)&&(j>0))
    {
        if (A[i]==B[j])
        {
            ++k;
            s[k]=A[i];
            --i; --j;
        }
        else
        {
            if (t[i-1][j]>t[i][j-1])
            {
                --i;
            }
            else --j;
        }
    }

    for (int i=k;i>=1;--i) fout << s[i] << ' ';
}
int main()
{
  read();
  sol();
    return 0;
}
