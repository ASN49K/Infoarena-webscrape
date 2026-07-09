#include<fstream>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
int T,N,X,S;
int main(){
    in>>T;
    for(;T;--T){
        S=0;
        in>>N;
        for(;N;--N){
            in>>X;
            S=S^X;
        }
        if(S) out<<"DA\n";
        else out<<"NU\n";
    }
    return 0;
}
