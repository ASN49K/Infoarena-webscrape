#include<iostream>
#include<fstream>
#define DN 1050
using namespace std;
fstream fin("cmlsc.in",ios::in),fout("cmlsc.out",ios::out);
int a[DN],b[DN],dmax[DN][DN],rez[DN];

int main()
{
    int n,m,i,j;
    fin>>n>>m;
    for(i=1; i<=n; i++)
    {
        fin>>a[i];
    }
    for(j=1; j<=m; j++)
    {
        fin>>b[j];
    }
    for(i=0; i<n; i++)
    {
        dmax[i][0]=0;
    }
    for(i=0; i<m; i++)
    {
        dmax[0][i]=0;
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                dmax[i][j]=dmax[i-1][j-1]+1;
            }
            else
            {
                dmax[i][j]=max(dmax[i][j],max(dmax[i-1][j],dmax[i][j-1]));

            }
        }
    }
        fout<<dmax[n][m]<<'\n';
        int rezl=0;
        i=n;
        j=m;
        while(i>0 && j>0)
        {
            if(a[i]==b[j])
            {
                rez[rezl++]=a[i];
                --i;
                --j;
            }
            else
            {
                if(dmax[i-1][j]>dmax[i][j-1])
                {
                    --i;
                }
                else
                {
                    --j;
                }
            }
        }
        for(i=rezl; i>=1; i--);
        {
            fout<<rez[i]<<" ";
        }
        fin.close();
        fout.close();
        return 0;
    }
