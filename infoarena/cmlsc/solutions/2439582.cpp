#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,sol[1025][1025],a[1025],b[1025],vec[1025],k;
int main()
{
    fin>>n>>m;
    sol[0][0]=0;
    for(int i=1; i<=n; i++){
        fin>>a[i];
        sol[0][i]=0;}
    for(int i=1; i<=m; i++){
        fin>>b[i];
        sol[i][0]=0;}


    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++){
        if(a[i]==b[j]){
            sol[i][j]=sol[i-1][j-1]+1;
        }
        else{
            if(sol[i-1][j]>sol[i][j-1])
                sol[i][j]=sol[i-1][j];
            else
                sol[i][j]=sol[i][j-1];
        }
    }

    for(int i=n; i>0; )
        for(int j=m; j>0; ){
            if(a[i]==b[j]){
                vec[++k]=a[i];
                --i;
                --j;}
            else if(sol[i-1][j]>sol[i][j-1])
                --i;
            else
                --j;
        }

    fout<<k<<'\n';

    for(int j=1; j<=k; j++)
        fout<<vec[j]<<" ";


    return 0;
}
