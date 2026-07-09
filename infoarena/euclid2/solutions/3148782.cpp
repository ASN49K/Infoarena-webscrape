#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int eu(int a,int b){
    if(!b) return a;
    return eu(b,a%b);
}

int main(){
    int a,b,n;
    in>>n;
    for(;n>0;n--){
    in>>a>>b;
    out<<eu(a,b)<<endl;
    }
    
}