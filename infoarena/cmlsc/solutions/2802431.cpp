#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout ("cmlsc.out");
int n, m;
int a[1024],b[1024];
int p[1024][1024];
int l=0;
int sol[1025];
void citire()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                p[i][j]=p[i-1][j-1]+1;
            }
            else
                p[i][j]=max(p[i-1][j],p[i][j-1]);
        }
    }
    int i=n;
    int j=m;
    while(i>0 && j>0)
    {

            if(a[i]==b[j])
            {
                sol[l++]=a[i];
                i--;
                j--;
            }
            else
                {
                    if(p[i][j-1]>p[i-1][j])
                    {
                        j--;
                    }
                    else
                    {
                        i--;
                    }
                }
    }

    fout<<l<<endl;
    for(int i=l-1;i>-1;i--)
        fout<<sol[i]<<" ";
}
int main()
{
    citire();
    return 0;
}
