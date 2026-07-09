#include <fstream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int t;
int euclid(int a, int b)
{
    while(b!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}


int main()
{
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<euclid(a,b)<<'\n';
    }
    return 0;
}
