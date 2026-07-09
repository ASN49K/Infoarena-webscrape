#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int euclid(int a, int b)
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
    int n, a, b;
    cin >> n;
    for(int i=0; i<n; ++i)
    {
        cin >> a >> b;
        cout << euclid(a, b) << '\n';
    }
}
