#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int n,m,a[100],b[100],x[100][100]{};
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(int j=1;j<=m;j++)
    {
        fin>>b[j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j]) x[i][j]=x[i-1][j-1]+1;
            else x[i][j]=max(x[i-1][j],x[i][j-1]);
        }
    }
    int i,j,k=0,rec[100];
    i=n;
    j=m;
    while(i>=1 || j>=1)
    {
        if(a[i]==b[j])
        {
            k++;
            rec[k]=a[i];
            i--;
            j--;
        }
        else {if(x[i][j-1]>x[i-1][j]) j--;
              else i--;}
    }
    fout<<k<<endl;
    for(i=k;i>=1;i--)
    {
        fout<<rec[i]<<" ";
    }
    
    
    
    
    /*for(int i=1;i<=n;i++)
    {
        fout<<endl;
        for(int j=1;j<=m;j++)
        {
            fout<<x[i][j]<<" ";
        }
    }*/



}