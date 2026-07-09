#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,T;
int euclid(int a, int b){
   if(b==0) return a;
   else
   return euclid(b,a%b);
	
};
int main(){
	fin>>T;
  while(T--)
	{
	fin>>a>>b;
	fout<<euclid(a,b)<<"\n";
}


	return 0;
}
