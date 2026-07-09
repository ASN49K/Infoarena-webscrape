#include<fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m,A[1050],B[1050],pd[1050][1050],sol[1050],k;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>A[i];
    for(int i=1;i<=m;i++) cin>>B[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(A[i]==B[j]) pd[i][j]=pd[i-1][j-1]+1;
            else pd[i][j]=max(pd[i-1][j],pd[i][j-1]);
    int i=n,j=m;
    while(i>=1 && j>=1)
        if(A[i]==B[j]) {sol[++k]=A[i]; --i; --j;}
        else if(pd[i-1][j]<pd[i][j-1]) --j;
        else --i;
    cout<<k<<'\n';
    for(int i=k;i>=1;i--) cout<<sol[i]<<' ';
}

