#include <cstdlib> 
#include <iostream> 
#include <fstream> 

 
using namespace std; 
int euclid(int A, int B){
	if(!b) return a;
	return euclid(b,a%b);
}
 
int main(void){ 
int a,b,r,n,i; 
ifstream f("euclid2.in"); 
ofstream f1("euclid2.out"); 
f>>n; 
for(i=1;i<=n;i++){ 
f>>a>>b; 
f1<<euclid(a,b)<<endl; 
} 
f.close();  
f1.close(); 
   
return 0;
}