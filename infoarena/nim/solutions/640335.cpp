#include<fstream>
using namespace std;
int main() {
int t,i,j,x,n,s;
ifstream in("nim.in");
ofstream out("nim.out");
in>>t;
for(i=0;i<t;i++) {
in>>n;
s=0;
for(j=0;j<n;j++) {
in>>x;
s=s^x;
}
if(s) out<<"DA\n";
else  out<<"NU\n";
}
in.close();
out.close();
return 0;
}