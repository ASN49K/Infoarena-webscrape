#include<fstream>
#include<iostream>
using namespace std;
int max(int a, int b)
{
    if (a>b)
     return a;
else return b;
}
int c[102][102], a[1024], b[1024];

  ofstream g("cmlsc.out");
  
  void afisare(int i, int j)
  {
       cout << "afisare(" << i << ", " << j << ");\n";
       if (c[i][j])
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
  }

int main()
{ int m, n, k=0, i, j;

  ifstream f("cmlsc.in");
    f>>m>>n;
    
   for(i=1;i<=m;i++)
     f>>a[i];
   for(i=1;i<=n;i++)
     f>>b[i];
     f.close();
     for(i=1;i<=m;i++)
       for(j=1;j<=n;j++)
     if(a[i]==b[j])
      c[i][j]=c[i-1][j-1]+1;
     else
       c[i][j]=max(c[i][j-1],c[i-1][j]);
       
       g << c[m][n] << endl;
       
      afisare(m, n);
      g << endl;
      g.close();
   
   system ("pause");
    return 0;
}
