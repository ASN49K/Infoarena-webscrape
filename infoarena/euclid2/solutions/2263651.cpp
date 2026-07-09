#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main(){
    int x;
    fin>>x;
int a,b,rest,i;
fin>>a>>b;
for(i=1;i<=x;i++){
while(b!=0){
    rest=a%b;
    a=b;
    b=rest;
}
fout<<a<< "\n";
}
return 0;
}
