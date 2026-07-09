#include <iostream>
#include <fstream>
#define file "euclid2"

using namespace std;

ifstream fin(file".in");
ofstream fout(file".out");

int T,a,b;

inline int cmmdc(int &a,int &b)
{
    int r;
    while(b)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
	fin>>T;

	while(T--)
	{
		fin>>a>>b;
		fout<<cmmdc(a,b)<<"\n";
	}

	return 0;
}
