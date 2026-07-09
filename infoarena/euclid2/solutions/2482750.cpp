#include <fstream>
#include <cstring>
using namespace std;

 ifstream cin ("euclid2.in");
 ofstream cout ("euclid2.out");

int cmmdc(int a,int b)
{
    if(b == 0)return a;
    return cmmdc(b,a%b);
}

int main()
{
    int x,y,t;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        cout << cmmdc(x,y) <<'\n';
    }
}
