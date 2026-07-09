#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int e(int a, int b)
{
    if (!b)
        return a;
    return e(b, a % b);
}

int main()
{
    int N, x,y;
    fin>>N;
    for(int i=1;i<=N;i++)
    {
        fin>>x>>y;
        fout<<e(x,y)<<'\n';
    }
    return 0;
}
