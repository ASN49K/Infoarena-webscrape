#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");
int n,t;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int s=0,x;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            s^=x;
        }
        if(s==0)
            cout<<"NU\n";
        else
            cout<<"DA\n";
    }
    return 0;
}
