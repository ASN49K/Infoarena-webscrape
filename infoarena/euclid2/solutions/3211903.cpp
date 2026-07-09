#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int Euclid(int x, int y)
{
    int r=x%y;
    while(r)
    {
        x = y;
        y = r;
        r = x%y;
    }
    return y;
}

int main()
{
    int N;
    fin >> N;
    for(int i=1; i<=N; i++)
    {
        int a, b;
        fin >> a >> b;
        fout << Euclid(a, b) << "\n";
    }
    return 0;
}

