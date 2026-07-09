#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;

int main(void)
{
	ifstream in;
	ofstream out;
	int n;
	in.open("euclid2.in");
	out.open("euclid2.out");
	string line;
	std::getline(in, line);
	std::stringstream parser;
	parser << line;
	parser >> n;
	for(int loop = 0; loop < n; ++loop)
	{
		int a, b;
		std::getline(in, line);
		std::stringstream parser;
		parser << line;
		parser >> a >> b;

		while(b != 0) 
		{
			int t = b;
			b = a % b;
			a = t;
		}

		out << a << endl;
	}

	in.close();
	out.close();
	return 0;
}