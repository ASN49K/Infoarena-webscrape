#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return cmmdc(b,a%b);
    }
}
int main()
{
    ifstream f("euclid.in");
    ofstream g("euclid.out");
    int a,b,t,i;
    f>>t;
    for(i=1;i<=t;i++){
        f>>a>>b;
        g<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
