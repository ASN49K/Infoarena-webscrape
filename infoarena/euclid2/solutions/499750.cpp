#include<iostream> 
#include<fstream> 
using namespace std; 
int main() 
{unsigned T,a,b,c; 
ifstream f("euclid2.in"); 
ofstream g("euclid2.out"); 
f>>T; 
while(T){ 
f>>a>>b;
if(a<b){
	c=a%b;
	a=b;
	b=c;
}
while(b){ 
c=a%b; 
a=b; 
b=c; 
} 
g<<a<<endl;  
T--; 
} 
f.close(); 
g.close(); 

}