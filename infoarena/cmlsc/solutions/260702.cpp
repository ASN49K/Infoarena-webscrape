#include<fstream>

using namespace std;

int max(int a, int b)
{ if(a>b) return a;
else return b;

}
int m,n,i,k,j,a[50],b[50],c[50][50];
ofstream g("cmlsco.out");
 void afisare(int i, int j)
  {

      
            if (c[i-1][j] < c[i][j] && c[i][j-1] < c[i][j])
            {
                afisare(i-1, j - 1);
                g << a[i] << ' ';
            }
            else if ((c[i-1][j] < c[i][j]) && (c[i][j-1] == c[i][j]))
                afisare(i-1, j);
            else if ((c[i][j-1] < c[i][j]) && (c[i-1][j] == c[i][j]))
                afisare(i, j-1);
            else if (c[i-1][j-1] == c[i][j])
                afisare(i - 1, j - 1);
            
       
  }
int main()
{



ifstream f("cmlsco.in");
f>>m>>n;
for(i=1;i<=m;i++)
f>>a[i];
for(j=1;j<=n;j++)
f>>b[j];
f.close();

 for(i=1;i<=m;i++)
 for(j=1;j<=n;j++)
 if(a[i]==b[j])
 c[i][j]=c[i-1][j-1]+1;
 else c[i][j]=max(c[i-1][j], c[i][j-1]);
 


   g<<c[m][n]<<endl;
   afisare(m,n);
       
   
g.close();
system ("pause");
return 0;
}
