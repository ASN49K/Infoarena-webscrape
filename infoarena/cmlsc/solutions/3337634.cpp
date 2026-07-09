#include <fstream>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

// declaring outside main for zeros
int d[1030][1030];
int main()
{
   /// declaring
   int n, m, a[1030], b[1030], i, j;

   ////reading
   cin >> n >> m;
   for (i = 1; i <= n; i++)
   {
      cin >> a[i];
   }

   for (i = 1; i <= m; i++)
   {
      cin >> b[i];
   }

   // algorithm
   for (i = n; i >= 1; i--)
   {
      for (j = m; j >= 1; j--)
      {
         if (a[i] == b[j])
         {
            d[i][j] = 1 + d[i + 1][j + 1];
         }
         else
         {
            if (d[i + 1][j] > d[i][j + 1])
            {
               d[i][j] = d[i + 1][j];
            }
            else
            {
               d[i][j] = d[i][j + 1];
            }
         }
      }
   }

   // reconstructing and outputting
   cout << d[1][1]<<endl;
   for (i = 1; i <= n;)
   {
      for (j = 1; j <= m;)
      {
         if (a[i] == b[j])
         {
            cout << a[i] << " ";
            i++;
            j++;
         }
         else
         {
            if (d[i + 1][j] > d[i][j + 1])
            {
               i++;
            }
            else
            {
               j++;
            }
         }
      }
   }


}
