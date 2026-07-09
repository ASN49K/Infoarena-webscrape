#include <iostream>
#include <fstream>
using namespace std;

int t,n;
long int N;
int le_rez;

ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
	f>>t;
	while(t--) {
		f>>n;
		while(n--){
			f>>N;
			le_rez ^= N; 
		}
		if(le_rez) g<<"DA";
		else g<<"NU";
		g<<"\n";
	}
}