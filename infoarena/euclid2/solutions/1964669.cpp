#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int n;

int cmmdc(int x, int y){
    int r;
    while(y!=0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
void solve(){
    for(int i=1,x,y;i<=n;i++){
        in>>x>>y;
        out<<cmmdc(x,y)<<"\n";
    }
}
int main(){
    in>>n;
    solve();
    return 0;
}
