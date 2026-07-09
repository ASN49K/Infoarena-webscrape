#include "fstream.h"
ifstream g("euclid2.in");
ofstream f("euclid2.out");
int t,a,b,c;
int main(){
    g>>t;
    for(;t--;){
    g>>a>>b;
    while(b) c=a%b,a=b,b=c;
    f<<a<<"\n";
    }
}
