#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
using namespace std;
int cmmdc(int a , int b){
	 int r ;
	 r=a%b;
	 while(r!=0){
		 a=b;
		 b=r;
		 r=a%b;
	 }
	 return b;
}
int main(){
	 int t , i , a , b ;
	 fin>>t;
	 for(i=1 ; i<=t ; i++){
		 fin>>a>>b;
		 fout<<cmmdc(a, b)<<endl;
	 }
return 0;
}
