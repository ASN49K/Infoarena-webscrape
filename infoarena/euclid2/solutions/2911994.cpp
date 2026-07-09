#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int cmmdc(int a, int b)
{
    while(b)
    {
        int r=a%b;
        a=b;
        b=r;
    }

    return a;
}

int n, a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        cout<<cmmdc(a, b)<<'\n';
    }

    cin.close();
    cout.close();
    return 0;
}
