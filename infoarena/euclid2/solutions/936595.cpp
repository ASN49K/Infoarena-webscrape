#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long a,b;
int t;

long cmmdc(long a, long b)
{long c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{f>>t;
 for(int i = 0; i < t; i++) {
	 f>>a>>b;
	 g<<cmmdc(a,b)<<endl;
 }
 f.close();
 g.close();
 return 0;
}
