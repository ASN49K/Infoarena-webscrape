#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
unsigned cmmdc(unsigned x , unsigned y){
	 if(!y) return x;
	 return cmmdc(y,x%y);}
int main(){
	 unsigned a , b , t , i;
	 fin>>t;
	 for(i=1 ; i<=t ; i++){
		 fin>>a>>b;
		 fout<<cmmdc(a,b)<<endl;
	 }
return 0;
}
