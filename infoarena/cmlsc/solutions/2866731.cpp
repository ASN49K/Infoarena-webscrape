#include <iostream>
#include <fstream>

using namespace std;
ifstream be("cmlsc.in");
ofstream ki("cmlsc.out");
int const nMax = 1025;
int a[nMax],b[nMax];
int n,m,db = 1;
int t[nMax][nMax];
void cmlsc()
{
    int hossz;
    for(int i=1;i<=n;i++)
    {
        t[i][0] = 0;
    }
    for(int j=1;j<=m;j++)
    {
        t[0][j] = 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
           if(a[i]==b[j])
           {
               t[i][j]=t[i-1][j-1]+1;
           }
           else
           {
               if(t[i-1][j]>t[i][j-1])
                    t[i][j] =  t[i-1][j];
               else t[i][j] = t[i][j-1];
           }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<t[i][j]<<' ';
        }
        cout<<endl;
    }
    hossz = t[n][m];
    int kozos[hossz+1];
    int i = n;
    int j = m;
    for(int k = 1 ; k<=hossz ; k++)
    {
        while(t[i][j] == hossz - k + 1)
        {
            j--;
        }
        j++;
        while(t[i][j] == hossz - k + 1)
        {
            i--;
        }
        i++;
        kozos[k] = a[i];
        i--;
        j--;
    }
    cout<<hossz<<endl;
    ki<<hossz<<endl;
    for(int i=hossz;i>=1;i--)
    {
        cout<<kozos[i]<<' ';
        ki<<kozos[i]<<' ';
    }
}
int main()
{
    be>>n>>m;
    for(int i=1;i<=n;i++)
    {
        be>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        be>>b[i];
    }
    cmlsc();
}
