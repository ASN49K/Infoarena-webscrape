#include<fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int euclid(int a,int b)
{
    if(!b) return a; ///b <= a
    return euclid(b,a % b);
}

int main()
{
    int t,a,b; cin >> t;
    while(t--)
        {
            cin >> a >> b;
            cout << euclid(a,b) << '\n';
        }
}
