#include<fstream>
using namespace std;
int main()
{	 int a,b,c;
	 ifstream fin("euclid2.in");
	 ofstream fout("euclid2.out");
	 fin>>c;
	 for(int i=1;i<=c;i++){
			 fin>>a>>b;
		 while(a!=b)
		 {	
				if(a>b)
					a=a-b;
				else
					b=b-a;
		 }
		 fout<<a<<endl;
	 }
return 0;
}
