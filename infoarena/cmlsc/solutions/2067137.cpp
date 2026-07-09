#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,j,i,n,c[1031][1031],a[1031],b[1031];
void afis(int n,int m){
if(n>=1&&m>=1)
if(a[n]==b[m]){afis(n-1,m-1);g<<a[n]<<" ";}
else {
    if(c[n-1][m]>c[n][m-1]) afis(n-1,m);
    else afis(n,m-1);

}



}
int main()
{f>>n>>m;
for(i=1;i<=n;i++) f>>a[i];
for(i=1;i<=m;i++) f>>b[i];
c[0][0]=0;
for(i=1;i<=n;i++)
for(j=1;j<=m;j++){
    if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
    else c[i][j]=max(c[i-1][j],c[i][j-1]);


}
g<<c[n][m]<<endl;
afis(n,m);
       return 0;
}
