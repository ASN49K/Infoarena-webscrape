#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int euclid(int a,int b){
    while(b){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main(){
   int t;
   cin>>t;
   for(int i=1;i<=t;++i){
    int a,b;
    cin>>a>>b;
    cout<<euclid(a,b)<<endl;
   }
return 0;
}

