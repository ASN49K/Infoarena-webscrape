#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int cmmdc(int a,int b)
{
    int r=a%b;
    while(r>0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        cout<<cmmdc(x,y)
        cout<<endl;
    }
    return 0;
}
