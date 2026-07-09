#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int A[1024],B[1024];
int main(){
	int a,b,cnt=0;
	cin >> a >> b;
	for(int i = 1; i <= a; i++){
		cin >> A[i];
		for(int j = 1; j <= b; j++){
           cin >> B[j];
		}
		if(A[i] == B[i]){
			cnt++;
			
		}
	}
	cout << cnt;
}