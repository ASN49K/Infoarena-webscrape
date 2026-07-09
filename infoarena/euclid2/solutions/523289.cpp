#include <iostream.h>
#include <fstream.h>

ifstream in ("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b);

main()
{
	unsigned int T, i, a, b;
	in >> T;
	for(i=1; i<=T; i++){
		in >> a >> b;
		out << cmmdc(a,b);
	}
	in.close();
	out.close();
}

int cmmdc(int a, int b){
	if (a%b==0)
		return b;
	else
		return cmmdc(b, a%b);
}



