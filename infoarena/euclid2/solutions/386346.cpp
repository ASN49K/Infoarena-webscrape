#include<fstream>
using namespace std;
int main()
{	 int a,b,c,d;
	 ifstream fin("euclid2.in");
	 ofstream fout("euclid2.out");
	 fin>>c;
	 for(int i=1;i<=c;i++){
			 fin>>a>>b;
		 while(b){
			 d=a%b;
			 a=b;
			 b=d;
		 }
		 fout<<a<<endl;
	 }
return 0;
}
