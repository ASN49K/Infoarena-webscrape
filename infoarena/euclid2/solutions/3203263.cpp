#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("euclib2.in");
    ofstream fout("euclid2.out");
    int T;
    fin>>T;
    for(int i=1; i<=T; i++){
        int a, b;
        fin>>a>>b;
        int mn=min(a,b);
        int mx=max(a,b);
        while(mn!=0){
            int r=mx%mn;
            mx=mn;
            mn=r;
        }
        fout<<mx<<endl;
    }


    return 0;
}

