#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int m,n;
int a[1030][1030];

int main()
{
    cin>>m>>n;
    int x;
    for(int i=2;i<m+2;i++){
        cin>>x;
        a[i][0] = x;
    }
    for(int i=2;i<n+2;i++){
        cin>>x;
        a[0][i] = x;
    }
    for(int i=0;i<=m+2;i++){
        a[i][n+2] = -1;
    }
    for(int i=0;i<=n+2;i++){
        a[m+2][i] = -1;
    }
    /// coloana , linia
    for(int i=2;i<m+2;i++){
        for(int j=2;j<n+2;j++){
            a[i][j] = max(a[i-1][j],a[i][j-1]);
            if(a[0][j]==a[i][0]){
                a[i][j]++;
            }
        }
    }
    cout<<a[m+1][n+1];
    cout<<"\n";
    int i=2;
    int j=2;
    for(int k=0;k<m+n-1;k++){
        if(a[i+1][j]>a[i][j+1]){ // i=3 j=2
            if(a[i+1][j]!=a[i][j]){
                cout<<a[i+1][0]<<" ";
            }
            i++;
        }else if(a[i+1][j]<a[i][j+1]){
            if(a[i][j+1]!=a[i][j]){
                cout<<a[0][j+1]<<" ";
            }
            j++;
        }else if(a[i+1][j]==a[i][j+1]){
            i++;
        }
    }
}
