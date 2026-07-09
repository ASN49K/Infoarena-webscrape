#include<fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

short mat[1026][1026];

int main() {
  int n,m,v1[1027],v2[1027];
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>v1[i];
    for(int i=1;i<=m;i++)
        cin>>v2[i];
    for (int i=n;i>=1;i--)
        for (int j=m;j>=1;j--) {
            if(v1[i]==v2[j])
                mat[i][j]=1+mat[i+1][j+1];
            else
                mat[i][j]=max(mat[i+1][j],mat[i][j+1]);
        }
    cout<<mat[1][1]<<endl;

    int i = 1, j = 1;
    while (i <= n && j <= m) {
        if (v1[i] == v2[j]) {
            cout << v1[i] << " ";
            i++;
            j++;
        } else if (mat[i+1][j] >= mat[i][j+1]) {
            i++;
        } else {
            j++;
        }
    }
    cout << endl;

}