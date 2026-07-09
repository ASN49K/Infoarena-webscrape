#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int t;
long long a,b;
int euclid(long long a, long long b)
{
    long long r=a%b;
    if(r==0) return b;
    else return euclid(b,r);
}
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b;
        cout<<euclid(a,b)<<endl;
    }
    cin.close();
    cout.close();
    return 0;

}