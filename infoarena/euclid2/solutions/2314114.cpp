#include <fstream>
using namespace std;
int main(){
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a, b, x;
fin>>x;
for(int i=1; i<=x; ++i){
fin>>a>>b;
while(a!=b){
    if(a>b)
        a=a-b;
    else b=b-a;
}
fout<<a;}
return 0;
}
