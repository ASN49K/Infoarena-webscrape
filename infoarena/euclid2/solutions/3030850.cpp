#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int euclid(int a,int b)
{
    if(!b)
        return a;
    return euclid(b,a%b);
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        cout << euclid(x,y);
    }
    return 0;
}
