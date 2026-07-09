#include <iostream>
#include<fstream>
using namespace std;
int euclid(int x, int y)
{
    if (y == 0)
        return x;
    else
        return euclid(y, x % y);

}
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a, b, c, T;
    fin >> T;
    while (T > 0)
    {
        fin >> a >> b;
        T--;
        c = euclid(a, b);
            fout << c << endl;
    }
}
