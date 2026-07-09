#include <iostream>
#include <fstream>
using namespace std;
int euclid(int a,int b){
    int r;
    r=a%b;
    while(a%b){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main(){
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,n;
    fin>>n;
    while(n){
        fin>>a>>b;
        fout<<euclid(a,b);
        if(n!=1)
            fout<<endl;
    n--;
    }
    return 0;
}
