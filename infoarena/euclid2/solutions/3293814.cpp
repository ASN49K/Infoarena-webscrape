#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int cmmdc(int a, int b);


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    while(n--)
    {
        int a, b;
        cin>>a>>b;
        cout<<cmmdc(a, b)<<"\n";
    }
    return 0;
}

int cmmdc(int a, int b)
{
    while(b > 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
