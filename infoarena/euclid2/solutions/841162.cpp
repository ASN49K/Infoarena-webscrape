#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main(){
	 int a , b , r , i ;
	 fin>>i;
	 for( ; i>0 ; i--){
		 fin>>a>>b;
		 while((r=a%b)!=0){
			 a=b;
			 b=r;
			 r=a%b;
		 }
	     fout<<b<<"\n";
	 }
return 0;
}
