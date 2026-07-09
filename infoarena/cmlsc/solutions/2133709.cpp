#include <fstream>
#define LGMAX 1025
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[LGMAX],b[LGMAX],n,m;
int lgmax[LGMAX][LGMAX];
int unde[LGMAX][LGMAX];
int main()
{
    int i,j;
    fin>>n;
    for(i=1;i<=n;i++)
        fin>>a[i];
    fin>>m;
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=n;i>0;i--)
    {
        for(j=m;j>0;j--)
        {
            if(a[i]==b[j])
                {lgmax[i][j]=1+lgmax[i+1][j+1];
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
        }
    }
    fout<<lgmax[1][1]<<'\n';
    i=j=1;
    while(i<=n&&j<=m)
    {
        if(unde[i][j]==1)
        {
            fout<<a[i]<<' ';
            i++;
            j++;
        }
        else
        {
            if(unde[i][j]==2)
            {
                i++;
            }
            else
                j++;
        }
    }

    return 0;
}
