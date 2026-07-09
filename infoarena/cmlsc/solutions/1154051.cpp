#include <fstream>

using namespace std;
int a[1025][1025];
int li[1025];
int ci[1025];
int subs[1025];
int main()
{int m,n,i,j,o=0;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
in>>m>>n;
for(i=1;i<=m;i++)
    in>>li[i];
for(i=1;i<=n;i++)
    in>>ci[i];
for(i=1;i<=m;i++)
for(j=1;j<=n;j++)
{if(li[i]==ci[j]) a[i][j]=a[i-1][j-1]+1;
else {if(a[i-1][j]>=a[i][j-1]) a[i][j]=a[i-1][j];
      if(a[i-1][j]<=a[i][j-1]) a[i][j]=a[i][j-1];
     }}
i=m;
j=n;
while(i>0&&j>0)
{
    if(li[i]==ci[j]) {subs[++o]=ci[j];
    j--;
    i--;}
   else{if(a[i-1][j]<=a[i][j-1]) j--;
    if(a[i-1][j]>=a[i][j-1]) i--;}
}
out<<a[m][n]<<endl;
for(i=o;i>=1;i--)
    out<<subs[i]<<" ";
if(o==0) out<<0;
    out.close();
    return 0;
}
