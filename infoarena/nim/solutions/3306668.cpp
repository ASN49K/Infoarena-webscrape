#include <fstream>

using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");
int main()
{
    int t;
    for(cin>>t;t;--t){
        cin>>n;
        int r=0;
        for(i=1;i<=n;i++){
            cin>>a;
            r=r^a;
        }
        if(r==0)cout<<"NU"<<'\n';
        else cout<<"DA"<<'\n';
    }
    return 0;
}
