#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
void euclid(int a,int b)
{
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        if(a<b)
            b=b-a;
    }
    cout << a << '\n';
}
int main()
{
    int x,y,t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> x >> y;
        euclid(x,y);
    }
    return 0;
}
