#include <fstream>
using namespace std;

int t,a,b;

int cmmdc (int a,int b){
if (!b) return a;
return cmmdc(b,a%b);
}

int main (){
ifstream in("euclid2.in");
ofstream out("euclid2.out");
in>>t;
for (;t;t--){
    in>>a>>b;
    out<<cmmdc(a,b)<<"\n";}
in.close();
out.close();
return 0;
}
