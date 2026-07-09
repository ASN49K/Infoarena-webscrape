#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int t , a , b;
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(a < b) swap(a,b);
        while(b)
        {
            int r = a%b;
            a = b;
            b = r;
        }
        cout << a << '\n';
    }
    return 0;
}
