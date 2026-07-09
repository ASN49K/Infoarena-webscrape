#include    <iostream>
#include    <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int GCD(int a, int b)
{
    if(!b)
        return a;
    return GCD(b, a%b);
}

void Read()
{
    int M;
    fin >> M;
    for(int i = 1; i <= M; i++)
    {
        int x, y;
        fin >> x >> y;
        fout << GCD(x, y) << "\n";
    }
}

int main()
{
    Read();
    return 0;
}
