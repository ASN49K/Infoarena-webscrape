#include<fstream>
using namespace std;

int euclid(int &a,int &b){
int r;
while(b){ r=b;
	b=a%b;
	a=r;
	}
return a;
}

int main(){
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T,x,y;
fin>>T;
for(int i01;i<T;i++) {fin>>x>>y; fout<<euclid(x,y)<<endl;}
return 0;
}