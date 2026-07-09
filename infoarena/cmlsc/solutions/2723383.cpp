#include <bits/stdc++.h>
using namespace std;
ifstream fcin("cmlsc.in");
ofstream fcout("cmlsc.out");

int n,m,a[1025],b[1025],mx[1025],maxi=0,sol[1025];

bool subsir(int niv, int v[])
{
    int prev=1,j,da;
    for(int i=1;i<=niv;i++){
        da=0;
        for(j=prev;j<=m;j++){
            if(v[i]==b[j]){
                da=1;
                prev=j;
                break;
            }
        }

        if(da==0)
            return 0;
    }
    return 1;
}

void backtrack(int niv, int prev)
{
    if(niv>n)   return;
    for(int i=prev+1;i<=n;i++){
        sol[niv]=a[i];
        if(subsir(niv,sol)){
            if(niv>maxi){
                maxi=niv;
                for(int j=1;j<=niv;j++)
                    mx[j]=sol[j];
            }
            backtrack(niv+1,i);
        }
    }
    return;
}

int main()
{
    fcin>>n;
    fcin>>m;
    for(int i=1;i<=n;i++)
        fcin>>a[i];
    for(int i=1;i<=m;i++)
        fcin>>b[i];

//    cout<<subsir(n,a)<<endl;

//    cout<<n<<":\n";
//    for(int i=1;i<=n;i++)
//        cout<<a[i]<<' ';cout<<endl;
//    cout<<m<<":\n";
//    for(int i=1;i<=m;i++)
//        cout<<b[i]<<' ';cout<<endl;

    backtrack(1,0);

    cout<<maxi<<endl;
    for(int i=1;i<=maxi;i++)
        cout<<mx[i]<<' ';

    return 0;
}
