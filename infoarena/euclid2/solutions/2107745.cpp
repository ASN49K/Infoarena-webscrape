#include <iostream>
#include <fstream>
using namespace std;
ifstream ("euclid2.in");
ofstream ("euclid2.out");
int a,b;

int main(){
    f>>a>>b;
    while(a!=b){
        if(a>b)a=a/b;
        if(b>a)b=b/a;
    }
    g<<a;
return 0;
}
