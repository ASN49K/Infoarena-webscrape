
#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int t;
long long a,b;
long long euclid(long long a,long long b)
{
    if(!b)
      return a;
    else
      return euclid(b,a%b);
}
int main()
{
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a>>b;
        cout<<euclid(a,b)<<'\n';
    }

    return 0;
}
