#include <fstream>

using namespace std;

int T, a, b, d, r, i;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int main()
{


    fin >> T;

    for (i = 1; i <= T; i++)

    {
        fin >> a >> b;

      while (b)
      {
        r = a%b;
        a = b;
        b = r;
      }
      fout << a << " ";
      fout << "\n";
    }

    return 0;
}
