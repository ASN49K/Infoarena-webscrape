#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int f(int a,int b)
{
    if(b==0)
        return a;
    return f(b,a%b);
}
int main()
{
    ios_base::sync_with_stdio();
    int t,a,b;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b;
        cout<<f(a,b)<<"\n";
    }
    return 0;
}
