#include <fstream>

using namespace std;
int a,b,t,r,i;
int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>a>>b;
        while(b!=0){
            r=b%a;
            a=b;
            b=r;
        }
        cout<<a<<'\n';
    }
    return 0;
}
