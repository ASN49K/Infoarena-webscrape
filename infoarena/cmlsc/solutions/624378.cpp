#include <fstream>

using namespace std;

const int nmax=1025;

int a[nmax][nmax],s1[nmax],s2[nmax],sub[nmax];
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int main()
{
int n,m,i,j,x=0;
cin>>n>>m;
for(i=1;i<=n;i++)cin>>s1[i];
for(i=1;i<=m;i++)cin>>s2[i];


for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        {
            if(s1[i]==s2[j]) a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=max(a[i-1][j], a[i][j-1]);
        }
i=n;j=m;
while(a[i][j]){
    while(a[i][j]==a[i-1][j])i--;
    while(a[i][j]==a[i][j-1])j--;

    sub[++x]=s1[i];
    i--;j--;
    }
cout<<a[n][m]<<"\n";
while(x){cout<<sub[x]<<" ";x--;}

    return 0;
}
