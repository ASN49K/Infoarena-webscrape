#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main(){
	 int t , i ;
	 long a , b ;
	 fin>>t;
	 for(i=1 ; i<=t ; i++){
		 fin>>a>>b;
		 int r ;
	     r=a%b;
	     while(r!=0){
		     a=b;
		     b=r;
		     r=a%b;
	 }
	 fout<<b<<endl;
	 }
return 0;
}
