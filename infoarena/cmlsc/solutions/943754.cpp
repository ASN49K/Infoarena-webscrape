#include <iostream>
#include <fstream>
using namespace std;
long long a[100001],maxi,n,b[100001],poz;
int main()
{
    ifstream fin("scmax.in");
    ofstream fout("scmax.out");
    fin>>n;
    for(int i=1;i<=n;i++)fin>>a[i];
    b[n]=1;
    for(int i=n-1;i>=1;i--)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]<a[j]&&b[i]<b[j]+1)b[i]=b[j]+1;
            if(b[i]==0)b[i]=1;
            if(b[i]>maxi){maxi=b[i];poz=i;}
        }
    }
    fout<<maxi<<'\n';
    //cout<<b[1439];
    for(int i=poz;i<=n&&maxi!=0;i++)
    {
        if(b[i]==maxi){fout<<a[i]<<" ";maxi--;}
    }
    fin.close();
    fout.close();
}
