#include <fstream>
int t, a, b, r;
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>t;
    for (int i=1; i<=t; i++)
    {
	in>>a>>b;
	r=a%b;
	while(r>0){
		a=b;
		b=r;
		r=a%b;
	}
	out<<b<<"\n";
    } 
    return 0;
}