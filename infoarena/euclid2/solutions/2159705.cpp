#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, x, y;

int Euclid(int a, int b)
{
    if(!b)
        return a;
    return Euclid(b,a%b);
}

int main()
{
    fin >> n;

    for(int i = 1; i <= n; i++)
    {
        fin >> x >> y;
        fout << Euclid(x,y) << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}
