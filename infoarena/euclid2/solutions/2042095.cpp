#include <iostream>

using namespace std;


int cmmdc(int a, int b)
{
    int t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int n,a,b;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    cin >> n;

    while(n--)
    {
        cin >> a >> b;
        cout << cmmdc(a, b) << endl;
    }

    return 0;

}
