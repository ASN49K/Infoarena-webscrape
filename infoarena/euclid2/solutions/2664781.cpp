#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int main()
{
    int n,i,a,b,r;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b;
        while(b>0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        cout<<a<<endl;
    }
    return 0;
}
