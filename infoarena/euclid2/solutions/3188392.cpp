#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
    int T;
    fin>>T;
    while(T!=0){
        int a,b;
        fin>>a>>b;
        while (b!=0) {
            int nr=b;
            b=a%b;
            a=nr;}
        fout<< a<<endl;
        T--;
    }
    
    return 0;
}
