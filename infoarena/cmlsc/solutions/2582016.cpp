#include <bits/stdc++.h>
using namespace std;
ifstream ci("cmlsc.in");
ofstream cou("cmlsc.out");

int v[1026][1026],a[1026],b[1026],n,m;
int afis[1026];
int k;
void citire()
{
    ci>>n>>m;
    int i;
    for(i=1; i<=n; i++)
    {
        ci>>a[i];
    }
    for(i=1; i<=m; i++)
    {
        ci>>b[i];
    }

}

void rez()
{
    int i,j;
//v[1][1]=1;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j] )
            {
                v[i][j]=v[i-1][j-1]+1;
            }
            else
            {
                v[i][j]=max(v[i-1][j],v[i][j-1]);
            }
        }
    }
    k=v[n][m];
    cou<<v[n][m]<<"\n";
    i=n;j=m;
    while(i&&j){
        if(a[i]==b[j]){
            afis[k--]=a[i];
            i--;
            j--;
        }else{
        if(v[i-1][j]>v[i][j-1] ){
            i--;
        }else{
        j--;
        }

        }
    }
    for(int i=1;i<=v[n][m];i++ ){
        cou<<afis[i]<<" ";
    }

}


int main()
{
    citire();
    rez();
    return 0;
}
