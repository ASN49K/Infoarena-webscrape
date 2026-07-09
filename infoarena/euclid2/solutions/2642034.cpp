//#include <iostream>
#include <fstream>

using namespace std;
ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");
int gcd(int a, int b) {
    if (b==0)
        return a;
    return gcd(b, a%b);
}
int main() {
    setbuf(stdout,NULL);

    int a, b, n;
    cin >> n;
    while (n)
    {
        cin >> a >> b;
        cout << gcd(a, b) << endl;
        n--;
    }
    return 0;
}

