#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int cmmdc(int a, int b)
{
    while(b != 0)
    {
        int r = a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        cout<<cmmdc(x,y)<<"\n";
    }
    return 0;
}
