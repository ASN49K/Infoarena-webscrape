#include<iostream.h>
#include<math.h>
int cmmdc(int a, int b);
int main() {
int a=0,b=0;
while(1) {
instream>>a;
instream>>b;
ostream<<cmmdc(a,b);
}
return 0;
}
int cmmdc(int a,int b) {
if(a%b==0)
return b;
else
return cmmdc(b,a%b);}