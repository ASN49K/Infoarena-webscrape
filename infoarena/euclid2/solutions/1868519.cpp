#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
ofstream out;
ifstream in;
unsigned char c[2000000];
int main(){
    in.open("ciur.in");
    out.open("ciur.out");
    int a,b;
    cin>>a>>b;
    while(a && b){
        if(a>b)a=a%b;
        else b=b%a;
    }
    cout<<a+b;
    return 0;
}
