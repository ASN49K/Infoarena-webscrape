#include<fstream>
#include<iostream>
#include <string.h>
using namespace std;


ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

typedef struct result{
	int lung;
	char s[100];
};

result calcul_subsir(int *a, int *b, int n, int m, int posA, int posB){
	int j, pos = -1;
	
	//cout << a[posA] << " "  <<posA<< " " << posB<< endl;
	if(posA >=m || posB >= n){
		result a;
		a.lung = 0;
		strcpy(a.s, " ");
		return a;
	}
		
	
	int aux = a[posA];
	
	for(j = posB; j < n; j++){
		if(aux == b[j]){
			pos = j;
			break;
		}
	}
	//cout << "tadamx: " << posA << " " <<posB <<endl;
	if(pos == -1){
		
		return calcul_subsir(a, b, n, m, posA + 1, posB); 
	}
	
	result res1 = calcul_subsir(a, b, n, m, posA + 1, pos + 1);
	res1.lung ++;
	char nr[100];
	char* r= itoa(a[posA], nr, 10);
	strcat(nr, " ");
	strcat(nr, res1.s);
	strcpy(res1.s, nr);
	result res2 = calcul_subsir(a, b, n, m, posA + 1, posB);
	
	//cout << "tadam: " << res1 << " " << res2 << " " << posA << " " <<posB <<endl;
	
	if(res1.lung > res2.lung)
		return res1;
	return res2;
}

int main(){

	int m,n,*a, *b, i;
	
	fin >> m >> n;
	a = new int[m];
	b = new int[n];
	
	for(i = 0; i < m; i++){
		fin >> a[i];
	}
	
	for(i = 0; i < n; i++){
		fin >> b[i];
	}
	result res = calcul_subsir(a,b,n,m,0,0);
	fout << res.lung << endl;
	fout << res.s;
	
	return 0;
}