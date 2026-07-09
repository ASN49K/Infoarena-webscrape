#include <fstream>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int rez[1025],k;
int lcs(int a[],int b[],int m,int n){
    int L[m+1][n+1];
    int i,j;
    for(int i=0;i<=m;++i)
        for(int j=0;j<=n;++j){
            if(i==0 || j==0)
                L[i][j]=0;
            else if(a[i-1]==b[j-1])
                L[i][j]=L[i-1][j-1]+1,rez[++k]=a[i-1];
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);
        }
        return L[m][n];
}

int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}

int main(){
   int m,n,a[1025],b[1025];
   cin>>m>>n;
   for(int i=0;i<m;++i)
    cin>>a[i];
   for(int i=0;i<n;++i)
    cin>>b[i];
    cout<<lcs(a,b,m,n)<<endl;
    for(int i=1;i<=k;++i)
        cout<<rez[i]<<" ";
return 0;
}

