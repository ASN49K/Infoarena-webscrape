#include<fstream> 

using namespace std; 

ifstream in("nim.in"); 
ofstream out("nim.out"); 

int T, N;
int main() 
{
	int i, numar, xorsum;
	in >> T; 

	while(T) 
	{
		in >> N; 
		xorsum = 0;
		for(i = 1; i <= N; i++) 
		{
			in >> numar; 
			xorsum = xorsum ^ numar; 
		}
		
		if(xorsum) out << "DA" << '\n'; 
		else out << "NU" << '\n';
		--T;
	}
}
