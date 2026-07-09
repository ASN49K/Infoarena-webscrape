#include <fstream>
using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");
int nim,t,n,x;
signed main()
{
    cin>>t;
    while(t--){
        cin>>n;
        nim=0;
        while(n--){
            cin>>x;
            nim^=x;
        }
        if(nim==0)
            cout<<"NU\n";
        else
            cout<<"DA\n";
    }
    return 0;
}
