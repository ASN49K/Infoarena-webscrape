#include <iostream>
#include <fstream>
using namespace std;
int main () {
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int T,a,b;
in>>T;
while(T!=0){
    in>>a;
    in>>b;
    while(a!=b){
        if(a>b)
            a=a-b;
            else
                b=b-a;
        }
     out<<a;
     T=T-1;
     }
return 0;
}
