#include<fstream.h>
long a,b,c;
int main(){
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	in>>a>>b;
	while(b!=0){
		c=a%b;
		a=b;
		b=c;
	}
	out<<a;
	in.close();
	out.close();
    return 0;
}
