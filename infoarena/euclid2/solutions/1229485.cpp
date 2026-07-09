#include <fstream>
using namespace std;

ifstream f1 ("euclid2.in"); //INTRARE
ofstream f2 ("euclid2.out"); //IESIRE

int main()
{
    int x,y,t;
    f1>>t;
    for(int i = 0; i < t; i++){
	    f1>>x;
	    f1>>y;
	    while(x!=y)
			if(x>y)
				x=x-y;
			else
				y=y-x;
		f2<<x<<"\n";
	}
    return 0;
}