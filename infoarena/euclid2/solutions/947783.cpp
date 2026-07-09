#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int n,x,y;
int euclid(int a,int b){
    if(!b) return a;
    else return euclid(b,a%b);
}
int main(){
    in>>n;
    for(;n;--n){
        in>>x>>y;
        out<<euclid(x,y)<<'\n';
    }
    return 0;
}
