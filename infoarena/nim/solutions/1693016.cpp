#include <fstream>

using namespace std;

ifstream cin ("nim.in");
ofstream cout("nim.out");

int n,t,sum,x;

int main(){
	
	cin >> t;
	
	while(t--){
		cin >> n;
		sum=0;
		for(int i=0; i<n; i++ )cin >> x, sum=sum^x;
		if(sum) cout << "DA\n";
		else cout << "NU\n";
	}
	
return 0;
}
