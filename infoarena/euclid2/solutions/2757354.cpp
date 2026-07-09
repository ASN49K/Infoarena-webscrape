#include <iostream>
#include <fstream>
using namespace std;
int main(){
    int a,b,i,T;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>T;
    for (i=1; i<=T; i++){
    fin>>a>>b;
    while (a!=b){
        if (a>b)
            a=a-b;
        else
            b=b-a;
    }
    fout<<a;
    }
    return 0;
}
