/**
Enunt:

*/

#include <iostream>

using namespace std;

int main ()
{
    FILE* in = freopen("euclid2.in","r",stdin);
    FILE* out = freopen("euclid2.out","w",stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int a, b;
        cin >> a >> b;
        while (b != 0)
        {
            int r = a % b;
            a = b;
            b = r;
        }
        cout << a << endl;
    }
    return 0;
}
