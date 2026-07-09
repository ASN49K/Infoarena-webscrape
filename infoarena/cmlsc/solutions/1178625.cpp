#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;
ifstream f;
ofstream g;

int i,j,a[1025],b[1025],n1,n2,m,c[1025][1025],q;



void matrice()
        {
        for(i=0;i<=n1;i++)c[i][0]=0;
        for(i=0;i<=n2;i++)c[0][i]=0;

        for(i=1;i<=n1;i++)
        for(j=1;j<=n2;j++)
                {
                 if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
                 else if(c[i-1][j]>c[i][j-1])c[i][j]=c[i-1][j];
                 else c[i][j]=c[i][j-1];
                }
        int n=0;
        while(c[n1][n2]!=0)
                {
                 while(c[n1][n2]==c[n1][n2-1]&&n2>0)n2--;
                 while(c[n1][n2]==c[n1-1][n2]&&n1>0)n1--;
                 n++;
                 a[n]=b[n2];
                 if(c[n1-1][n2]>c[n1][n2-1])n1--;else n2--;
                }

        g<<n<<'\n';
        for(i=1;i<=n;i++)g<<a[i]<<' ';

        }





int main()
{
f.open("cmlsc.in");
g.open("cmlsc.out");
f>>n1>>n2;


for(i=1;i<=n1;i++)f>>a[i];
for(i=1;i<=n2;i++)f>>b[i];

matrice();





f.close();
g.close();
return 0;
}
