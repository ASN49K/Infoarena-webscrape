#include <iostream>
#include <fstream>
#define file "euclid2"

using namespace std;

ifstream fin(file".in");
ofstream fout(file".out");

int main() {

	int T,a,b,r;
	fin>>T;

	while(T--)
	{
		fin>>a>>b;
		while(b)
        {
            r = a%b;
            a = b;
            b = r;
        }
        fout<<a<<"\n";
	}

	return 0;
}
