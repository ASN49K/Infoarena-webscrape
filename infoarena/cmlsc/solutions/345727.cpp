#include<fstream>
using namespace std;
short m,n,a[1025],b[1025],rez[1025][1025],c[1025][1025],sir[1025],tot=0;;
short k1=m,k2=n;
int main()
{ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

in>>m>>n;
for(int i=1;i<=m;i++) in>>a[i];
for(int i=1;i<=n;i++) in>>b[i];
for(int i=1;i<=n;i++)
 c[0][i]=0;
for(int i=1;i<=m;i++)
 c[i][0]=0; 
for(int i=1;i<=m;i++)
 for(int j=1;j<=n;j++)
  {if(a[i]==b[j]) {c[i][j]=c[i-1][j-1]+1;rez[i][j]=-2;}
   else if(c[i][j-1]>=c[i-1][j]) {c[i][j]=c[i][j-1]; rez[i][j]=-1;}
        else {c[i][j]=c[i-1][j];rez[i][j]=1;}
         
         
         }
      out<<c[m][n]<<'\n';   
tot=0;k1=m;k2=n;
while(k1!=0 && k2!=0)  
  { if(a[k1]==b[k2]) {tot++;sir[tot]=a[k1];}
    switch(rez[k1][k2])
     {case -2: {k1--;k2--;break;}
     case -1:{k2--;break;}
      case 1:{k1--;break;}
      default:break; }    
         
         }
for(int i=c[m][n];i>0;i--) out<<sir[i]<<" ";   
   
     
    return 0;}
