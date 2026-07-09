#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1025],b[1025];
vector <int> sol;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //read
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=m; i++) cin>>b[i];

    //cmlsc
    int mat[n+1][m+1] = {};
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (a[i]==b[j]) mat[i][j]=1+mat[i-1][j-1];
            else mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
        }
    }

    //get secvence
    int i=n,j=m;
    while(mat[i][j]!=0){
        if (a[i]==b[j]) {
            sol.push_back(a[i]);
            i-=1;
            j-=1;
        }
        else if(mat[i-1][j]>mat[i][j-1]) i-=1;
        else j-=1;
    }

    //write
    cout<<mat[n][m]<<"\n";
    for (i=sol.size()-1; i>=0; i--) cout<<sol[i]<<" ";
    return 0;
}
