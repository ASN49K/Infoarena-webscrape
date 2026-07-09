/******************************************************************************************
*           .--.																		  *
* ::\`--._,'.::.`._.--'/::			@author Ana M. Mihut	@course InfoArena EduArchive  *
* ::::. `  __::__ ' .:::::			@alias  LT-Kerrigan		@date   31.05.2014			  *
* ::::::-:.`'..`'.:-::::::			@link   http://infoarena.ro/problema/euclid2		  *
* ::::::::\ `--' /::::::::			@detail	gcd Euclid / Binary  						  *
*																						  *
*******************************************************************************************/

#include <iostream>
#include <fstream>

long gcd(long a, long b){
	return (b != 0) ? gcd(b, a%b) : a;
}

int main(){
	long n, a, b;

	FILE *in = freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	fscanf(in, "%d", &n);

	for (long i = 0; i < n; i++){
		fscanf(in, "%d %d", &a, &b);
		std::cout << gcd(a, b) << "\n";
	}
}