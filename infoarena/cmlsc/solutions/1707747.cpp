#include<fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
 
int x[1025][1025],t[1025],n,m,a[1025],b[1025];
 
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(a[i]==b[j])
                x[i][j] = 1+x[i-1][j-1];
            else{
                if(x[i-1][j] > x[i][j-1])
                    x[i][j] = x[i-1][j];
                else
                    x[i][j] = x[i][j-1];
            }
        }
    int i=n, j=m;
    while(i!=0 && j!=0)
        if(a[i]==b[j]){
            t[++t[0]]=a[i];
            --i;
            --j;
        }
        else
            if(x[i-1][j]<x[i][j-1])
                --j;
            else
                --i;
    cout<<t[0]<<'\n';
    for(int i=t[0];i;i--)
        cout<<t[i]<<" ";
    return 0;
}
