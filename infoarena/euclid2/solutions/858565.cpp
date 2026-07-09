#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
void euc(int a, int b){
if(b) euc(b,a%b);
else g<<a<<"\n";

}
main(){
int a,b,t,i;
f>>t;
for(i=0; i<t;i++){
f>>a>>b;
euc(a,b);
}
}
