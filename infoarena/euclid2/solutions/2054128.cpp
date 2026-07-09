#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a,int b){
   if(b==0) return a;
      else return cmmdc(b,a%b);
}
int main(){
    int n,a,b,c;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>n;
    for(int i=0;i<n;i++){
        in>>a;
        in>>b;
        c=cmmdc(a,b);
        out<<c<<"\n";

    }
    in.close();
    out.close();
return 0;

}
