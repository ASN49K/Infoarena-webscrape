#include <iostream>
#include <fstream>

using namespace std;
ifstream in("cmmdc.in");
ofstream out("cmmdc.out");

int main()
{
    int a,b,T;
    in>>T;
    for(int i=1; i<=T; ++i){
    in>>a;
    in>>b;
    while(a!=b){
        if(a>b){
        a=a-b;}
    else b=b-a;}
    out<<a<<endl;
    }
    return 0;
}
