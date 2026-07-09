#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,nr1,nr2;
void citire(){
	f>>n;
}
void div(){
    int i;
	for(i=1;i<=n;i++){
		f>>nr1>>nr2;
	while(nr1!=nr2){
		if(nr1>nr2) 
			nr1-=nr2;
		else 
			nr2-=nr1;
	}
	g<<nr1<<"\n";
	}
}
int main(){
	citire();
	div();
	g.close();
	return 0;
}

		