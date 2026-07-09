#include <fstream>
#include <iostream>

using namespace std;

ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

int div(int a , int b){
    if (!b)
        return a;
        return div(b, a % b);
}

int main(){
    int n;
    fi>>n;
    for(int i=0;i<n;i++){
        int a , b;
        fi>>a>>b;
        fo<<div(a,b)<<'\n';
        cout<<div(a,b)<<'\n';
    }
}
