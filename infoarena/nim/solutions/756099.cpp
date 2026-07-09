
#include <fstream>
using namespace std;

int main(void)
{
 long t,j,i,n,s,z;
 fstream fin("nim.in",ios::in);
 fstream fout("nim.out",ios::out);
 fin >> t;
 for (i = 0;i < t;i += 1)
  {
   fin >> n;
   s = 0;
   for (j = 0;j < n;j += 1)
    {
     fin >> z;
     s ^= z;
    }
   if (s != 0)
     {
      fout << "DA\n";
     }
    else
     {
      fout << "NU\n";
     }
  }
 fin.close();
 fout.close();
 return 0;
}
