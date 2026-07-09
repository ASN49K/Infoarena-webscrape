#include <fstream>
#include <iostream>
using namespace std;

int euclid (int a,int b)
{
 if(b==0)
 	return a;
 	
 	else
 	
 	return euclid(b,a % b);

}

int main(){
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	int a,b,n;
	in>>n;
	for (int i=1;i<=n;i++)
		{
			in>>a>>b;
			out<<euclid(a,b)<<"/n";
			}
		in.close();out.close();
	return 0;
	}
