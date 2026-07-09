#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euc(int a,int b){
    while(b != 0){
        int x = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int t,x,y;
    f>>t;
    for(int i=0;i<t;i++){
        f>>x>>y;
        g<<euc(x,y)<<"\n";
    }
    f.close();
    g.close();
    return 0;
}
