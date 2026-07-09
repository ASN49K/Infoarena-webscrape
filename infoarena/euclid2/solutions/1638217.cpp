#include <iostream>
#include <fstream>

//Algoritmul lui Euclid
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int cmmdc(int a, int b){
    if(a==0){
        g<<b<<endl;
    }

    while(b!=0){
        if(a>b){
            a = a - b;
        }else{
            b = b - a;
        }
    }
    g<<a<<endl;

}
int main()
{
    int a,b;
    int i,T;
    f>>T;
    for(i=1; i<=T; i++){
        f>>a>>b;
        cmmdc(a,b);
    }

    f.close();
    g.close();
    return 0;
}
