#include <cstdio>
int t, a, b, r;
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>t;
    for (int i=1; i<=t; i++)
    {
	in>>a>>b;
	if(a<b){
		r=a;
		a=b;
		b=r;
	}			
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