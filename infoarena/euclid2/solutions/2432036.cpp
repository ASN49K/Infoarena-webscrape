#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int main()
{
    int t,a,b,r;
    cin >> t;
    for (int i=1;i<=t;i++)
    {
        cin >> a >> b;
        while (b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        cout << a << "\n";
    }
}
