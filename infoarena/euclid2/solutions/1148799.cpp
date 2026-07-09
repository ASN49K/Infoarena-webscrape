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
int cmmdc2(int a, int b){
    int aux;
    while(b){
        aux=b;
        b=a%b;
        a=aux;
    }
    return a;
}
int main(){
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    while(n--)
        f>>a>>b, g<<cmmdc2(a, b)<<"\n";
    return 0;
}
