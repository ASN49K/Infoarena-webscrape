#include <fstream>
using namespace std;

ifstream f1 ("euclid2.in"); //INTRARE
ofstream f2 ("euclid2.out"); //IESIRE

int main()
{
    int a,b,t;
    f1>>t;
    for(int i = 0; i < t; i++){
	    f1>>a;
	    f1>>b;
	    int c;
	    while (b) {
	        c = a % b;
	        a = b;
	        b = c;
	    }
	    f2<<a<<"\n";
	}
    return 0;
}