#include <fstream>
using namespace std;
ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");
int main()
{int a, b, n, r, i;
    cin >> n;
    for (i=1; i<=n; i++) {
        cin >> a >> b;
        while (b>0) {
            r = a % b;
            a = b;
            b = r;
        }
        cout << a ;
    }
    return 0;
}
