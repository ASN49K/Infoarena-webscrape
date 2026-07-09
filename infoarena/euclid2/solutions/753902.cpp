#include <fstream>
using namespace std;

int euclid (int a,int b)
{int r= a % b;
 while (r)
 {a=b;
 b=r;
 r=a%b;}
 return b;
}

int main(){
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	int a,b,n;
	in>>n;
	for (int i=1;i<=n;i++)
		{
			in>>a>>b;
			out<<euclid(a,b)<<endl;
			}
	in.close();out.close();
	return 0;
	}
