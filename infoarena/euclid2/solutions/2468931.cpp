#include <iostream>
#include <fstream>
using namespace std;

ifstream in("pic.in");
ofstream out("pic.out");

int cmmdc(int a, int b){
    while(a != b)
        if(a < b) b-=a;
        else a -= b;
    return a;
}

int main(){
    int t,a,b;
    in>>t;
    for(int i = 0; i < t; i++){
        in>>a>>b;
        out<<cmmdc(a , b)<<"\n";
    }
}
