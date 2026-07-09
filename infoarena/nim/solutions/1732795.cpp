#include <fstream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

string problemName = "nim";
string inFile = problemName+".in";
string outFile = problemName+".out";
ifstream fin(inFile.c_str());
ofstream fout(outFile.c_str());

int main(){
    int t, n, test, i, x, sxor;
    fin>>t;
    for(test = 1;test <= t;test++){
        fin>>n;
        sxor = 0;
        for(i = 1;i <= n;i++){
            fin>>x;
            sxor ^= x;
        }
        if(sxor){
            fout<<"DA";
        }else{
            fout<<"NU";
        }
        fout<<'\n';
    }
    return 0;
}
