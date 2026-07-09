#include<fstream>
#include<iostream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int main() {
    int a,b,r;
    cout<<"a=";cin>>a;
    cout<<"b=";cin>>b;
    r=a%b;
    while(r) {
        a=b;
    b=r;
    r=a%b;
    }
    cout<<"cmmdc: "<<b;
    return 0; }
