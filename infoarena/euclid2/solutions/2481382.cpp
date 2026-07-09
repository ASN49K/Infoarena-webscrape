#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int n, a, b, x;
    fin>>n;
    for(int i=0;i<n;i++){
        fin>>a>>b;
        while(b){
            x = a%b;
            a = b;
            b = x;
        }
        fout<<a<<endl;
    }
    return 0;
}