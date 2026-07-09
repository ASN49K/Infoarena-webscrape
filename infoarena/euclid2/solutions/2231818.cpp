#include <fstream>

using namespace std;
 ifstream fin("cmmdc.in");
 ofstream fout("cmmdc.out");
  int cmmdc(int a, int b)
    {
        if(b == 0) return a;
            cmmdc(b, a%b);
    }
int main()
{
        int a, b, n;
         fin >> n;
          for(int i = 1; i <= n; ++i)
          {
              fin >> a >> b;
              fout << cmmdc(a, b) << endl;
          }

    return 0;
}
