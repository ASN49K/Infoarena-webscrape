#include<iostream>
#include<fstream>
using namespace std;
int a, b, n;
int cmmdc1(int a, int b){
    while(a!=b)
    {
        if(a>b)a-=b;
        else b-=a;
    }
    return b;
}
int main(){
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    while(n--)
        f>>a>>b, g<<cmmdc1(a, b)<<"\n";
    return 0;
}
