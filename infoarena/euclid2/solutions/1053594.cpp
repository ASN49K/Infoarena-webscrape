#include <iostream>
#include <fstream>
using namespace std;
inline int euclid(int a,int b)
{
	if (b == 0)return a;
	else return euclid(b, a%b);

}
int main()
{
	int n, a, b;
	ifstream citire;
	ofstream scriere;
	citire.open("euclid2.in");
	scriere.open("euclid2.out");
	citire >> n;
	for (int i = 0; i < n; i++)
	{
		citire >> a >> b;
		scriere << euclid(a, b)<<"\n";
	}
	citire.close();
	scriere.close();
	return 0;
}