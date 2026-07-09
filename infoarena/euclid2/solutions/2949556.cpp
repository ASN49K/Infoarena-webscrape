#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main(){
    int n,a,b,r;
    in>>n;
    while(n--){
        in>>a>>b;
        while(b){
            r=a%b;
            a=b;
            b=r;
        }
        out<<a<<endl;
    }
    return 0;
}