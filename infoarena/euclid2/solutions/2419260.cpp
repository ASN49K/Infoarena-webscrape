#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, x, y;

int gcd(int a, int b){

if(!a) return b;
else return(b % a, a);
}
int main(){
fin>>n;
for(int i = 1; i <= n; i++){
fin >> x >> y;
fout<<gcd(x, y)<<endl;
}
return 0;
}


