#include <iostream>
using namespace std;
int n, i, a, b, r;
int main()
{
    cin >> n;
    for (i=1;i<=n;i++) {
        cin >> a >> b;
        while (b>0) {
            r = a%b;
            a = b;
            b = r;
        }
        cout << a << '\n';
    }
    return 0;
}
