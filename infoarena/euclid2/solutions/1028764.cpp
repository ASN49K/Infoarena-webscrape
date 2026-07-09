#include <iostream>
#include<fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");


int main()
{
    int a,b,cmmdc,t;
    f >>t;
    for(int i=1;i<=t;++i){
        f >>a>>b;
        for(int r=a%b;r!=0;r=a%b){
            a=b;
            b=r;
        }
        cmmdc=b;
        g <<cmmdc<<"\n";
    }



    return 0;
}
