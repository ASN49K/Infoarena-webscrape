#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int cmmdc(int a, int b)
{
    int r;
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
    while(t--)
    {
        cin>>a>>b;
        cout<<cmmdc(a, b)<<'\n';
    }
    cin.close();
    cout.close();
    return 0;
}
