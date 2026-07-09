#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

void euclid(int a ,int b){
    while(a!=b){
     if(a>b) a-=b;
     else b-=a;
    }
    g<<a<<endl;
}
int main()
{
    int T,a,b;
    f>>T;
    for(int i=1;i<=T;i++){
        f>>a>>b;
        euclid(a,b);
    }
    return 0;
}

