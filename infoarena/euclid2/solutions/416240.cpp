#include <cstdlib> 
#include <iostream> 
#include <fstream> 

 int a,b,n,i; 
using namespace std; 

int euclid(int A, int B){
	if(!B) return A;
	return euclid(B,A%B);
}
 
int main(void){ 

ifstream f("euclid2.in"); 
ofstream f1("euclid2.out"); 
f>>n; 
for(;n;--n){ 
f>>a>>b; 
f1<<euclid(a,b)<<endl; 
} 
f.close();  
f1.close(); 
   
return 0;
}