#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a,int b)
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
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int t;
    cin >> t;
    while(t--)
    {
        int x,y;
        cin >> x >> y;
        cout << cmmdc(x,y) << "\n";
    }
    return 0;
}
