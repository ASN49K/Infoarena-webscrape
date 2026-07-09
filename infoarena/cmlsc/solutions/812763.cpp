#include<iostream>
#include<fstream>
using namespace std;
#define MAX_N 1500

int N, M; // lungimile celor doua siruri
int a[MAX_N], b[MAX_N]; // cele doua siruri
int stack[MAX_N], position[MAX_N], maxim;
void read(){
	ifstream f("cmlsc.in");
	
	f >> N >> M;
	
	for(int i=1; i<=N; i++){
		f >> a[i];
	}
	for(int i=1; i<=M; i++){
		f >> b[i];
	}
}


bool find_stack(int number, int pos){
	
	for(int i=1; i<= stack[stack[0]]; i++ ){
		if(number == stack[i] and pos == position[i])
			return true;
	}
	
	return false;
}


void LCS(int size_a, int size_b, int max){
	if(max > maxim)
		maxim = max;
	
	if(size_a && size_b){
		
		if(a[size_a] == b[size_b]){
			if(!find_stack(a[size_a], size_a)){
				stack[++stack[0]] = a[size_a];
				position[stack[0]] = size_a;
				LCS(size_a-1,size_b-1, max+1);
			}
		
		}else{
			LCS(size_a-1,size_b, max);
			LCS(size_a, size_b-1, max);
		}
		
	}

}

int main(){
	
	read();
	LCS(N,M,0);
	
	ofstream g("cmlsc.out");
	g << maxim << '\n';
	for(int i=stack[0]; i>=1 ; i--){
		g << stack[i] << " ";
	}

	return 0;
}
