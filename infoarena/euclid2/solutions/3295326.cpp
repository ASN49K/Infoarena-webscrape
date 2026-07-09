#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int CMMDC(int a, int b){
 int r;
while(b){
    
    r=a%b;
    a=b;
    b=r;
}
return a;
} 

int main(){
    int a; int b;
int T;
cin>>T;
while(fin>>a>>b){
    fout<<CMMDC(a,b)<<endl;
}
    
}