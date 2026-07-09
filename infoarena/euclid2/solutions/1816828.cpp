#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main(){
    int a, b, r, n;
    in>>n;
    for(int i=1; i<=n; i++){
        in>>a>>b;
        r=a;
        while(r!=0){
            r=a%b;
            a=b;
            b=r;
        }
        out<<a;
    }
    return 0;
}
