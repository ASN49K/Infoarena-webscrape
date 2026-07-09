#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int cmmdc(int a, int b)
{
    if(b==0) return a;
    else return cmmdc(b,a%b);
}
int main()
{
    int x,a,b,rest;
    cin >> x;
    for (int i = 1; i <= x; i ++)
    {
        cin >> a >> b;
        cout << cmmdc(a,b) << "\n";
    }
    return 0;
}
