#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int GCD(int a, int b){
if(!b)
    return a;
return GCD(b, a%b);
}
int main(){
int x;
int nr1, nr2;
fin>>x;
for(int i=1; i<=x; ++i){
    fin>>nr1>>nr2;
    fout<<GCD(nr1, nr2)<<endl;
}
return 0;

}
