#include<iostream>
#include<fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define MAX 1030
int n,m;
int v1[MAX];
int v2[MAX];
int mat[MAX][MAX];
int rez[MAX];

void read()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>v1[i];
    }
    for(int i=1;i<=m;i++)
    {
        fin>>v2[i];
    }
}

int maxlength()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
            {
                mat[i][j]=mat[i-1][j-1]+1;
            }
            else
            {
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }
    return mat[n][m];
}

void sir()
{
    int i=n;
    int j=m;
    int k=0;
    while(i>0 && j>0 && mat[i][j]!=0)
    {
        if(v1[i]==v2[j])
        {
            k++;
            rez[k]=v1[i];
            i--;
            j--;
        }
        else
        {
            if(mat[i-1][j]>mat[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    for(int i=k;i>=1;i--)
    {
        fout<<rez[i]<<" ";
    }
}

int main ()
{
    read();
    fout<<maxlength();
    fout<<'\n';
    sir();
    fin.close();
    fout.close();
    return 0;
}
