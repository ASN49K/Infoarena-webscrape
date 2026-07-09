#include<fstream>
#define maxn 1030
using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");

int i,j,n,m,k=0;
int a[maxn],b[maxn],s[maxn];
int c[maxn][maxn];

inline int max(int a, int b){
       if (a>b) return a; else return b;
}

int main(){
    fi>>n>>m;
    
    for(i=1;i<=n;i++) fi>>a[i];
    for(i=1;i<=m;i++) fi>>b[i];
    
    for(i=0;i<=n;i++) c[i][0]=0;
    for(j=0;j<=m;j++) c[0][j]=0;
    
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
         if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
         else c[i][j]=max(c[i-1][j],c[i][j-1]);
    
    i=n; j=m;
    while(c[i][j]!=0) {
                       if (a[i]==b[j]) { s[c[i][j]]=a[i]; i--;j--;}
                       else if (c[i-1][j]>c[i][j-1]) i--;
                            else j--;
                      }
                      
    fo<<c[n][m]<<"\n";
    for(i=1;i<=c[n][m];i++) fo<<s[i]<<" ";
    
    fi.close();
    fo.close();
    return 0;
}
