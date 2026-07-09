#include<fstream>
using namespace std;
int main()
{
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	long n,a,b;
	in>>n;
	while(n>0){
		n-=1;
		in>>a>>b;
		while(a!=b){
			if(a>b){
				a=a-b;
			}
			else b=b-a;
		}
		out<<a<<endl;
	}
	in.close();
	out.close();
	return  0;
}