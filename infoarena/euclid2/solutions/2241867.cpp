#include <iostream>
#include <fstream>

using namespace std;
int n, x, y;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc(int a, int b)
{
    int r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
     fin >> n;
     for(int i = 0; i < n ; ++i)
    {
        fin >> x >> y;
        fout << cmmdc(x, y) << endl;
    }

  return 0;
}
