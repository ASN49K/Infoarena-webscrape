#include<fstream.h>
void main (){
int a,b,d;
ifstream f("euclid2.in");
f>>a;f>>b;
while(a!=b){
if(a>b) a=a-b;
	else b=b-a;
}
d=a;
ofstream g("euclid2.out");
g<<d;
}





