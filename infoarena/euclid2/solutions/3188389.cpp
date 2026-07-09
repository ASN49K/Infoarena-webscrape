#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.in");

int euclid(int a, int b){
    while (b!=0) {
        int nr=b;
        b=a%b;
        a=nr;}
    if(a==1) return 0;
   return a;
}
int main() {
    int T;
    cin>>T;
    while(T!=0){
        int a,b;
        fin>>a>>b;
        fout<<euclid(a,b)<<endl;
        T--;
    }
    
    return 0;
}
