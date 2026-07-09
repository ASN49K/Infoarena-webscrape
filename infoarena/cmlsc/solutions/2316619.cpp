//#include <iostream>
#include <fstream>

using namespace std;
int d[1050][1050];
int v[1050],f[1050],rez[1050];
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int j=1;j<=m;j++)
        cin>>f[j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(v[i]==f[j]){
                d[i][j]=d[i-1][j-1]+1;
                //d[i][j].second=d[i-1][j-1];
            }
            else{
                d[i][j]=max(d[i][j-1],d[i-1][j]);
            }
        }
    }
    int i=n,j=m,cont;
    cont=d[n][m];
    cout<<d[n][m]<<"\n";
    while(cont!=0){
        if(v[i]==f[j]){
            rez[cont]=v[i];
            cont--;
            i--;
            j--;
        }
        else{
            if(d[i-1][j]>d[i][j-1]){
                i--;
            }
            else
                j--;
        }
    }
    for(int i=1;i<=d[n][m];i++){
        cout<<rez[i]<<" ";
    }
    return 0;
}
