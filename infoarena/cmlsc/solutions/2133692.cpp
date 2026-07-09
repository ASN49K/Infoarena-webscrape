#include <fstream>
#define MAX 1030

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int a[MAX];
int b[MAX];
int lgmax[MAX][MAX];
int unde[MAX][MAX];

int main()
{int i, j;
    fin>>n>>m;
    for(i=1;i<=n;i++) fin>>a[i];
    for(i=1;i<=m;i++) fin>>b[i];


    for(i=n;i>0;i--)
        for(j=m;j>=1;j--)
            if(a[i]==b[j])
            {
                lgmax[i][j]=1+lgmax[i+1][j+1];
                unde[i][j]=1;
            }
            else
            {
                if(lgmax[i+1][j]>lgmax[i][j+1])
                {
                    lgmax[i][j]=lgmax[i+1][j];
                    unde[i][j]=2;
                }
                else
                {
                    lgmax[i][j]=lgmax[i][j+1];
                    unde[i][j]=3;
                }
            }

    //afisare
    fout<<lgmax[1][1]<<'\n';
    i=1; j=1;
    while(i<=n && j<=n)
    {
        if(unde[i][j]==1)
        {fout<<a[i]<<' '; i++; j++;}
        else if(unde[i][j]==2) i++;
        else j++;
    }

    return 0;
}
