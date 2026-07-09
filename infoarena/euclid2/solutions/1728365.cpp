#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main(){

long n,a,b,r;
f>>n;
for(int i=1;i<=n;i++){
    f>>a>>b;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    g<<a<<endl;
}


return 0;
}
