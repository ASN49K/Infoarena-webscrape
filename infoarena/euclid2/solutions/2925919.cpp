#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
void euclid(int a,int b)
{
    int r;
    while(a != 0)
    {
        r=b%a;
        b=a;
        a=r;
    }
    cout << b << '\n';
}
int main()
{
    int x,y,t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> x >> y;
        if(x<y)
            euclid(x,y);
        else
            euclid(y,x);
    }
    return 0;
}
