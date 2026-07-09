#include <iostream>
#include <fstream>

using namespace std;
struct rezultat
{
    int x,y;
};

int a[1025],b[1025];
   rezultat rez[1025][1025];

 int main()
 {
  ifstream f("cmlsc.in");
  ofstream g("cmlsc.out");

  int n,m;
   f >> n >> m;
   for (int i=1; i<=n; i++)
     {
         f >> a[i];
         rez[i][0].x = 0;
     }

   for (int i=1; i<=m; i++)
     {
            f >> b[i];
            rez[0][i].x = 0;
     }

   for (int i=1; i<=n; i++)
   {
       for (int j=1;j<=m;j++)
       {
          if (a[i] == b[j]) {rez[i][j].x = rez[i-1][j-1].x + 1; rez[i][j].y = 0; }
                 else { rez[i][j].x = max(rez[i-1][j].x,rez[i][j-1].x);
                        if (rez[i][j-1].x > rez[i-1][j].x ) rez[i][j].y = 1; else rez[i][j].y = 2;  }
       }
   }

int maxim = 0,x = 0,y = 0;
 for (int i=1; i<=n; i++)
   for (int j=1; j<=m; j++)
    {
     if (rez[i][j].x > maxim && rez[i][j].y == 0) { maxim = rez[i][j].x;
                                          x = i;
                                          y = j;
                                        }
    }

  int afis[1025],poz=1;

  afis[poz] = b[y];
  poz++; x--; y--;
    while (rez[x][y].x)
    {
      if (!rez[x][y].y) {afis[poz] = b[y]; x--; y--; poz++; }
        else {
          if (rez[x][y].y == 1 ) y--; else x--;
        }
    }
    poz--;
g << poz << endl;
for (int i=poz;i>=1;i--)
    g << afis[i] << " ";

     return 0;
 }
