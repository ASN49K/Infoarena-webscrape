#include <iostream> 
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
} 
 
int main()
{
    int n,a,b;
	fin >> n;
	for (int i = 0; i < n; ++i) {
		fin >> a >> b;
		fout << euclid(a,b)<<endl;
	} 
    return 0;
}
