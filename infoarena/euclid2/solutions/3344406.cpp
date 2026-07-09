#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");
int n,m,x,y,teste;

int cmmdc(int a, int b)
{
    while (b)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    cin>>teste;
    for (int i=1;i<=teste;i++)
    {
        cin>>x>>y;
        cout<<cmmdc(x,y)<<endl;
    }
    return 0;
}
