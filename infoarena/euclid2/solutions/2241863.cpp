#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc(int a, int b)
{
    if (b == 0) return a;
    return cmmdc(b, a%b);

}
int main()
{
     int n;
     fin >> n;
     for (int i = 0; i < n; ++i)
    {
        int x, y, ans;
        fin >> x >> y;
        ans = cmmdc(x, y);
        fout << ans << endl;
    }

  return 0;
}
