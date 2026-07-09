#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main(){
    int n,a,b,i,j,sol;
    in>>n;
    for(i=0;i<n;++i){
        in>>a>>b;
        sol=1;
        for(j=2;j<=min(a,b);++j){
            if(a%j==0&&b%j==0){
                sol=j;
            }
        }
        out<<sol<<endl;
    }
    
    return 0;
}