#include <fstream>
#include <cstring>

using namespace std;

 ifstream cin ("euclid2.in");
 ofstream cout ("euclid2.out");

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

int n, a, b;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        cout << cmmdc(a, b) << "\n";
    }
}
