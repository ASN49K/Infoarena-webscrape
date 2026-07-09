#include <fstream>

using namespace std;

int cmmdc(int a, int b);

int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int n,x,y;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>x;
        cin>>y;
        cout<<cmmdc(x,y)<<"\n";
    }
    cin.close();
    cout.close();
}

int cmmdc(int a, int b)
{
    int r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}