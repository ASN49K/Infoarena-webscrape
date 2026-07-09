#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int div1(int a, int b){
int r=0;


while(a%b!=0){
r=a%b;
a=b;
b=r;	
}

/*
r=a%b;
while(r!=0){
a=b;
b=r;
r=a%b;
}
*/


return b;

}


int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
	int a, b;
	cin >> a >> b;
	cout << div1(a, b)<<'\n';
	}




}
