#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int euclidScaderi(int a,int b){
    while(a!=b){
        if(a>b) a=a-b;
        else b=b-a;
    }
    return a;
}
int main(){
    int t,a,b,i;
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>a>>b;
        cout<<euclidScaderi(a,b)<<'\n';
    }
    return 0;
}
