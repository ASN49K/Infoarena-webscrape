#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n;
    in>>n;
    for(;n>0;--n){
        int a,b;
        in>>a>>b;
        if(a<b) swap(a,b);
        while(b){
            a=a%b;
            swap(a,b);
        }
        out<<a<<"\n";
    }
}
