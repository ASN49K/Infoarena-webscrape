#include<fstream>
#include<math.h>
using namespace std;
int cmmdc(int a, int b){
if (a%b==0)
return b;
else
return cmmdc(b,a%b);}
int main (){
int a,b,t;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
in>>t;
if (1<=t && t<=100000){
int i;
for (i=1; i<=t; i++){
in>>a;
in>>b;
if (2<=a && a<=pow(10,9)*2 && 2<=b && b<=pow(10,9)*2){
out<<cmmdc(a,b);}}}
out.close();
in.close();
return 0;}