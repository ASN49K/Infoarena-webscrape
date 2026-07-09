#include <fstream>
#include <cstdlib>
using namespace std;
int *a,*b, **c,m,n,p, nr, *o;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

inline int maxim(int a,int b)
{
   return ((a > b) ? a : b);
}
int main()
{
   in >> m >> n;
   a = (int *) malloc(sizeof(int) * (n+1));
   o = (int *) malloc(sizeof(int) * (n+1));

   b = (int *) malloc(sizeof(int) * (m+1));
   c = (int **) malloc(sizeof(int) * (m+1));
   for(int i=1;i<=m;i++)
   {
       c[i] = (int *) malloc(sizeof(int) * (n+1));
   }
   for(int i=1;i<=m;i++)
        in >> a[i];

   for(int i=1;i<=n;i++)
        in >> a[i];
   for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i] == a[j])
                    c[i][j] = c[i-1][j-1]+1;
            else    c[i][j] = maxim(c[i-1][j],c[i][j-1]);
   for(int i=m,j=n;i;)
      {
          if(a[i]== a[j])
          {
              o[++nr] = a[i], --i, --j;

          }
          else
            if(c[i-1][j] < c[i][j-1])
               --j;
            else
                --i;
      }
      out << nr << "\n";
      for(int i=nr;i;i--)
        out << o[i] << " ";
   return 0;
}
