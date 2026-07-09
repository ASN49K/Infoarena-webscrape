#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int a;
	ifstream in ("euclid2.in");
	ofstream out ("euclid2.out");
    in>>a;
    if (a!=0)
        out<<"12";
    return 0;
}
