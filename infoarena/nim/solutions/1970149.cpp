#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int T, N, i, j;
int SumXor, NR;

int main()
{
    fin >> T;
    for (i=1; i<=T; i++)
    {
        fin >> N;
        SumXor=0;
        for (j=1; j<=N; j++)
        {
            fin >> NR;
            SumXor^=NR;
        }
        if (SumXor==0)
          fout << "NU\n";
        else
          fout << "DA\n";
    }
    fin.close();
    fout.close();
    return 0;
}
