#include <iostream>
#include <stdio.h>
 
using namespace std ;
 
int main(){
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
	int n ;
	cin >> n
	for (int i = 0 ; i< n ; i++){	
		int a, b ;
		cin >>a >> b ;
		while (a != b){
			if (a>b) {a -= b ;} else b-=a ;
		}  		
		cout << a ;
	}
    return 0  ;
}