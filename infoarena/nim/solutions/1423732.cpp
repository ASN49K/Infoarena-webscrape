#include<fstream>
using namespace std;

ifstream fin ("nim.in" );
ofstream fout("nim.out");

int N, Q, i, j, X, xorsum;

void CodeExpert(){
    fin >> Q;
    for(Q = Q; Q >= 1; Q --){
        fin >> N;
        xorsum = 0;
        for(j = 1; j <= N; j ++){
            fin >> X;
            xorsum = (xorsum ^ X);
        }
        if(xorsum != 0)
            fout << "DA\n";
        else
            fout << "NU\n";
    }
    return;
}

int main(){
    CodeExpert();
    return 0;
}
