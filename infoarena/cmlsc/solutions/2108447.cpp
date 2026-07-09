#include <iostream>
#include <fstream>

using namespace std;

int g[100001];
int main()
{
    int n,k,i,v[100001],max1,f=1,j,gasit;
    ifstream q("scmax.in");
    ofstream w("scmax.out");
    q>>n;

    g[n]=1;
    for(i=1;i<=n;i++) q>>v[i];
    for(i=n-1;i>=1;i--)
    {
        g[i]=1;
        max1=1;
        for(j=i+1;j<=n;j++)
        {
            // if(g[j]==0) g[j]=1;
            if(v[i]<v[j]&&g[j]>=max1) {g[i]=g[j]+1;max1=g[i];}
        }
    }

    for (i=1;i<=n;i++)
                if(g[i]>max1) {max1=g[i]; f=i;}
    w<<max1<<endl;
    k=max1; gasit=f;
    for(i=1;i<=n;i++)
    {

        if(i==f) {w<<v[i]<<" ";k--;gasit=i;}
        if(g[i]==k&&v[i]>v[gasit]) {w<<v[i]<<" ";k--;gasit=i;}
    }

    return 0;
}
