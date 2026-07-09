
#include <fstream>
using namespace std;

int main(void)
{
 fstream fin("euclid2.in",ios::in);
 fstream fout("euclid2.out",ios::out);
 long T,a,b,i,c;
 fin >> T;
 for (i = 0;i < T;i += 1)
  {
   fin >> a >> b;
   while (b != 0)
    {
     c = a % b;
     a = b;
     b = c;
    }
   fout << a << "\n";
  }
 fin.close();
 fout.close();
 return 0;
}
