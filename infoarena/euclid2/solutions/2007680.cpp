#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b;
int T,i;
int euclid(int a, int b){
   if(b==0) return a;
   else
   return euclid(b,a%b);
	
};
int main(){
	fin>>T;
	for(i=0;i<T;i++)
	{
	fin>>a>>b;
	fout<<euclid(a,b)<<endl;
}


	return 0;
}
