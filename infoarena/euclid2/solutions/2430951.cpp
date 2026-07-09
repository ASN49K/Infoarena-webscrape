#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
void citire()
{
    int t,r,a,b;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        r=0;
        cin>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        cout<<a<<'\n';
    }
}
int main()
{
    citire();
    return 0;
}
