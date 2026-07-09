#include <cstdlib>
#include <fstream>

using namespace std;

const int NMAX = 1031;

int v[3][NMAX], C[NMAX][NMAX];

inline int _max(int x, int y) {return x >= y ? x : y;}
int main()
{
   int i, j, k;
   ifstream in("cmlsc.in");
   ofstream out("cmlsc.out");

   in >> v[0][0] >> v[1][0];
   for(i = 1; i <= v[0][0]; ++i)
   {
       in >> v[0][i];
   }
   for(i = 1; i <= v[1][0]; ++i)
   {
       in >> v[1][i];
   }

   for(i = 1; i <= v[0][0]; ++i)
   {
      for(j = 1; j <= v[1][0]; ++j)
      {
          if(v[0][i] == v[1][j])
          {
             C[i][j] = 1 + C[i-1][j-1];
          }
          else {
                  C[i][j] = _max(C[i-1][j], C[i][j-1]);
               }
      }
   }
   v[2][0] = k = C[v[0][0]][v[1][0]];
   for(i = v[0][0], j = v[1][0]; i && j; )
   {
         if(v[0][i] == v[1][j])
         {
             v[2][k--] = v[0][i];
             --i;
             --j;
         }
         else if(C[i-1][j] > C[i][j-1]) --i;
              else --j;
   }

   out << v[2][0] << '\n';
   for(i = 1; i <= v[2][0]; ++i)
   {
        out << v[2][i] << ' ';
   }
   out << '\n';

   return EXIT_SUCCESS;
}
