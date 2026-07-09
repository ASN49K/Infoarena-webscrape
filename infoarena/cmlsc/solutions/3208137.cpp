#include <fstream>
#include <vector>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int a[10001][10001];
int s1[10001];
int s2[10001];
int n,m;

vector<int> rasp;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s1[i];
    }
    for(int i=1;i<=m;i++){
        cin>>s2[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i]==s2[j]){
                a[i][j]=a[i-1][j-1]+1;
            }else{
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    cout<<a[n][m]<<"\n";
    int i=n;
    int j=m;
    while(i>0&&j>0){
        if(s1[i]==s2[j]){
            rasp.push_back(s1[i]);
            i--;
            j--;
        }else{
            if(a[i-1][j]>a[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    for(int i=rasp.size()-1;i>=0;i--){
        cout<<rasp[i]<<" ";
    }
}
