#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main (){
int x, a, b, rest;
fin>>x;
for(int i=1; i<=x; ++i){
    fin>>a>>b;
    while(b){
        rest=a%b;
        a=b;
        b=rest;
    }
    fout<<a<<endl;
}
    return 0;
}
