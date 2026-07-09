#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int T, a, b, r;

int cmmdc(int a, int b){
	if(b == 0)
    {
		return a;
	}
	else
    {
		return cmmdc(b, a%b);
	}
}


int main()
{
    fin >> T;

    while(fin >> a >> b)
    {
        fout << cmmdc(a, b) << endl;
    }

    return 0;
}
