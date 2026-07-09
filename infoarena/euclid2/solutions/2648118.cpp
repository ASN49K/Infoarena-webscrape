#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a,int b){
    while(a!=b){
        if(a<b) b-=a;
        else a-=b;
    }
    return a;
}

void solve(){
    int x,y;
    in>>x>>y;
    out<<cmmdc(x,y)<<'\n';
}

int main(){
    int n;
    in>>n;
    while(n--) solve();
    return 0;
}