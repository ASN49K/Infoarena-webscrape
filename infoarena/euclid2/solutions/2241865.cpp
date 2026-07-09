#include <iostream>
#include <fstream>

using namespace std;
int n, x, y;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc(int a, int b)
{
    if (b == 0) return a;
    return cmmdc(b, a%b);

}
int main()
{
     fin >> n;
     for(; n; --n)
    {
        fin >> x >> y;
        fout << cmmdc(x, y) << endl;
    }

  return 0;
}
