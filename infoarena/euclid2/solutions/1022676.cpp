#include <fstream>
using namespace std;
int main()
{
    int a, b, r;
    ifstream in("cmmdc.in");
    ofstream out("cmmdc.out");
    in>>n;
    for(int i=1; i<=n; i++){
    	in>>a>>b;
	r=a%b;
	while(r>0){
        		a=b;
        		b=r;
        		r=a%b;
    	}
        	out<<b<<"\n";
return 0;
}
