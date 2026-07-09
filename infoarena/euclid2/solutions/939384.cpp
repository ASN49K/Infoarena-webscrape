#include <iostream>
#include <stdio.h>
 
using namespace std ;
 
int main(){
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
	int n ;
	cin >> n;
	int a, b ;
	for (int i = 0 ; i< n ; i++){			
		cin >>a >> b ;
		while (a != b){
			if (a>b) {a -= b ;} else b-=a ;
		}  		
		cout << a << "\n";
	}
	cout.flush();
    return 0  ;
}