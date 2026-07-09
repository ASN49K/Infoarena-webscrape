#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int eucli(int a, int b)
{
    int r=0;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int t, a, b;
    cin >> t;
    while(t)
    {
        cin >> a >> b;
        cout << eucli(a, b) << '\n';
        t--;
    }
}
