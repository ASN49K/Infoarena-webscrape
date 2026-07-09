#include<fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int op, r, a, b;
int euclid(int a, int b)
{
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    cin >> op;
    while(op--)
    {
        cin >> a >> b;
        cout << euclid(a, b) << "\n";
    }
    return 0;
}


























