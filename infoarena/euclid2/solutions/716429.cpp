#include<fstream>
using namespace std;
long cmmdc(long x , long y){
	 if(!y) return x;
	 return cmmdc(y,x%y);}
int main(){
	 ifstream fin("euclid2.in");
     ofstream fout("euclid2.out");
	 long a , b , t;
	 fin>>t;
	 for(t ; t ; --t){
		 fin>>a>>b;
		 fout<<cmmdc(a,b)<<"\n";
	 }
fin.close();
fout.close();
return 0;
}
