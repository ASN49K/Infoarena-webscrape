#include <iostream>
#include <fstream>
using namespace std;
int T,a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main(){
    f>>T;
    while(T!=0){
        f>>a>>b;
        while(a!=b){
            if(a>b)a=a-b;
            if(a<b)b=b-a;
        }
        g<<a<<endl;
        T--;
    }
    f.close();
    g.close();
return 0;
}
