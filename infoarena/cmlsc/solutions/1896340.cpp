#include <stdio.h>
#include <algorithm>
using namespace std;
int x[1025],y[1025],a[1025][1025],n,m;
FILE* f;
FILE* g;

void read(){
    fscanf(f,"%d %d",&n,&m);
     //   printf("%d %d",n,m);
    for(int i=1;i<=n;i++)
        fscanf(f,"%d",&x[i]);
    for(int i=1;i<=m;i++)
        fscanf(f,"%d",&y[i]);
}
void solve(int n, int m){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(x[i]==y[j]) a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=max(a[i-1][j],a[i][j-1]);
    }
    fprintf(g,"%d \n",a[n][m]);
    int k=1,s[1025];
    while(n>=1 && m>=1){
        if(x[n]==y[m]){
            s[k]=x[n];
            k++;
            //printf("%d ",x[n]);
            n--;
            m--;
        }
        else{
            if(a[n-1][m]>a[n][m-1])
                n--;
            else m--;
        }
    }
    for(int i=k-1;i>=1;i--)
        fprintf(g,"%d ",s[i]);
}
int main()
{
    f=fopen("cmlsc.in","r");
    g=fopen("cmlsc.out","w");
    read();

    solve(n,m);
//    cout << "Hello world!" << endl;
    return 0;
}
