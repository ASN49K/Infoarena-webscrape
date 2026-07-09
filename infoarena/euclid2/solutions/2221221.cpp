#include <iostream>
#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int gcd(int a, int b)
{
    int c;
    while(b)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main()
{
    int T,a,b;

    cin >> T;
    for(int i=1; i<=T; i++)
    {
        cin >> a >> b;

        cout << gcd(a,b) << endl;
    }

    return 0;
}
