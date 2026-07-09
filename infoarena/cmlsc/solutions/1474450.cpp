#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main()
{	
	
	int M[1024];
	int N[1024];
	int Rez[1024];
	int m,n;
	fin >> m;
	fin >> n;
	int lungime = 0;

	for (int i = 0 ; i < m; i ++)
		fin >> M[i];
	for (int i = 0 ; i < n; i ++)
		fin >> N[i];
	int z = 0;
	if (m < n) {
		for (int i = 0; i < m; i ++){
			
			for (int x = z; x < n ; x++){
				if (M[i] == N[x]){
					z = x;
					Rez[lungime] = M[i];
					lungime ++;
					break;
				}
			}
		}


	}else {
		for (int i = 0; i < n; i ++){
			
			for (int x = z; x < m ; x++){
				if (N[i] == M[x]){
					z = x;
					Rez[lungime] = N[i];
					lungime ++;
					break;
				}
			}
		}


	}
	fout << lungime << endl;
	for (int i = 0 ; i < lungime; i++){
		fout << Rez[i] << " ";
	}
}


