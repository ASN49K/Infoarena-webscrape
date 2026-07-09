#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int i, j, n, m, k;
int b[1030], a[1030], v[1030];
int d[1030][1030];
int main() {
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=m;i++)
        cin>>b[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else{
                d[i][j]=max(d[i][j-1], d[i-1][j]);
            }
        }
    }
    cout<<d[n][m]<<"\n";
    i=n;
    j=m;
    while(i>=1 && j>=1){
        if(a[i]==b[j]){
            v[++k]=a[i];
            i--;
            j--;
        }
        else{
            if(d[i-1][j]>d[i][j-1])
                i--;
            else
                j--;
        }
    }
    reverse(v+1, v+k+1);
    for(i=1;i<=k;i++)
        cout<<v[i]<<" ";


}
