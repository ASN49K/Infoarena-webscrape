#include <fstream>
using namespace std;
int main() {
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long c,t,a,b;
fin>>t;
for (int i=1;i<=t;i++) {
fin>>a>>b;
while (b) {
c=a%b;
a=b;
b=c;
}
fout<<a<<'\n';
}
fout.close();
return 0;
}
