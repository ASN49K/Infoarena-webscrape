#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){
    int N;
    fin>>N;
    int i,a,b,c=1;
    for(i = 0; i < N; i++){
        fin>>a>>b;
        c = a%b;
        while(c){
            a = b;
            b = c;
            c = a%b;
        }
        fout<<a;
    }
}
