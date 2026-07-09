#include <fstream>
int a,b,i,T,r;
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int main()
{
    cin>>T;
    for(i=1; i<=T; i++)
    {
        cin>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        cout<<a<<'\n';
    }
    cin.close();
    cout.close();
    return 0;
}
