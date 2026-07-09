#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int n;
pair <int, int> p;

int cmmdc(pair <int, int > p)
{
    int a = p.first, b = p.second, r;
    while(b)
    {
        r = b;
        b = a % b;
        a = r;
    }
    return a;
}

void init()
{
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>p.first>>p.second, cout<<cmmdc(p)<<'\n';
}

int main()
{
    init();
    return 0;
}
