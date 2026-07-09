#include <fstream>

using namespace std;

ifstream fin( "nim.in" );
ofstream fout( "nim.out" );

int Q;

int main()
{
    fin >> Q;

    int N, nr, ans;

    for( int i = 1; i <= Q; ++i )
    {
      fin >> N;

      ans = 0;

      for( int j = 1; j <= N; ++j )
      {
        fin >> nr;

        ans = ans ^ nr;
      }

      ( ans ) ? fout << "DA\n" : fout << "NU\n";
    }

    fin.close();
    fout.close();

    return 0;
}
