#include <fstream>
using namespace std;
ifstream cin("euclin2.in");
ofstream cout("euclid2.out");
int t,a,b;
int euclid(int a, int b)
{
    int r=a%b;
    if(r==0) return b;
    else return euclid(b,r);
}
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b;
        cout<<euclid(a,b);
    }
    return 0;

}