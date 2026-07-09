#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int CMMDC(int a, int b)
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
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << CMMDC(a, b) << endl;
    }
    cin.close();
    cout.close();
    return 0;
}
