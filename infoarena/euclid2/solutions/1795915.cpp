#include<fstream>
#include<iostream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,r,z,t;
int main(){
    fin>>t;
    for(z=1;z<=t;z++){
        fin>>a>>b;
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<"\n";
    }
    return 0;
}
