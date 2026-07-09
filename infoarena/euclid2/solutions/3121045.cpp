#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int T;

int cmmdc(int a, int b)
{
    while(b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    cin >> T;
    while(T--)
    {
        int a, b;
        cin >> a >> b;
        cout << cmmdc(a, b) << '\n';
    }
    
    return 0;
}