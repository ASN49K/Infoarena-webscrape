#include <fstream>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int T,N,S;

int main()
{
    fin >> T;
    while(T--)
    {
      fin >> N;
      S = 0;
      for(int i = 1; i <= N; ++i)
        {
          int X;
          fin >> X;
          S = S ^ X;
        }
      if (S)
        fout << "DA\n";
      else
        fout << "NU\n";
    }
    return 0;
}
