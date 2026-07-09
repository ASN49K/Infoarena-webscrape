#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int t,x,y;
int cmmdc(int a,int b){
    while(b!=0){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    cin>>t;
    while(t--){
        cin>>x>>y;
        cout<<cmmdc(x,y)<<'\n';
    }
    return 0;
}
