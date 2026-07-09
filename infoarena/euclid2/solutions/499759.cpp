#include<iostream> 
#include<fstream> 
using namespace std; 
int main() 
{int T,a,b,c; 
ifstream f("euclid2.in"); 
ofstream g("euclid2.out"); 
f>>T; 
for(int i=0;i<T;i++){ 
f>>a>>b;
if(a<b){
	c=a%b;
	a=b;
	b=c;
}
while(a%b){ 
c=a%b; 
a=b; 
b=c; 
} 
g<<b<<"n/";  

} 
f.close(); 
g.close(); 
return 0;
}
