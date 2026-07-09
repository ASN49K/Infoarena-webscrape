#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int euclidImpartiri(int a,int b){
    while(b){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main(){
    int t,a,b,i;
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>a>>b;
        cout<<euclidImpartiri(a,b)<<'\n';
    }
    return 0;
}
