#include <fstream>
using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");
int t,n,x;
signed main()
{
    cin>>t;
    while(t--){
        cin>>n;
        int nim=0;
        for(int i=1;i<=n;i++){
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
