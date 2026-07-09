#include <fstream.h>
#define NM 1025
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[NM],b[NM],d[NM][NM],n,m,cmlsc[NM];

int main(){
	int i,j,k;
	
	fin>>m>>n;
	for ( i = 1; i <= m; i++)
		fin >> a[i];
	
	for ( i = 1; i <= n; i++)
		fin >> b[i];
	
	for ( i = 1; i <= m; i++) // testeaza ficare din a
		for ( j = 1; j <= n; j++) // cu fiecare din b
			if ( a[i] == b[j] ) d[j][i] = d[j - 1][i - 1] + 1; // daca sunt a[i] == b[j] atunci distanta d[i][j] este egala cu distanta 
														      // formata de elementul precedent lui j din sirul B cu elementele din A pana la i-1
															  // nu ne intereseaza si daca j-1 a fost egal cu i-1 pentru ca nu vrem sa luam pe i din A cu ambele atat j cat si j-1.
															  // deci valoarea lui d[j][i] va avea valoare pe care a avut j-1 inainte de a ajunge in i
			else	// altfel
				if ( d[j][i - 1] < d[j - 1][i] )
						d[j][i] = d[j - 1][i];
					else
						d[j][i] = d[j][i - 1];
					
			/*
				avem nevoie de d[j][i - 1] < d[j - 1][i] deoarece
			
				pt : 1 7 3 9 8 si 7 5 8
					
					avem
					
					0 1 1 1 1
					0 1 2 2 2
					0 1 2 2 2
				
				pt : 2 3 4 5 si 3 5 6
					
					avem
					
					0 1 1 1 1
					0 1 1 1 2
					0 1 1 1 2
					
				primul exemplu e un caz in care se foloseste prima ramura a if-ului iar al doilea este pentru al doilea(pozitia d[5][3])
			*/
					
	// reconstruim sirul. facem dinamica inapoi.
					
	i = m; j = n; k = 0;
			
	while (i && j)

		if ( a[i] == b[j]) { // daca cele doua sunt egale atunci putem merge pe diagonala
							 // deoarece nu ne mai intereseaza decat subsirul care s-a format pana la valoarea i-1 cu elementul j-1
			cmlsc[++k] = a[i];
			i--;
			j--;
		} else
			if (d[j - 1][i] > d[j][i - 1]) // mergem pe ramura pe care este format un subsir cel mai lung subsir pentru aceasta pozitie.
				j--;
			else
				i--;
	
	fout << k << "\n";
			
	for (i = k; i > 0; i--)
		fout << cmlsc[i] << " ";
	
	fout << "\n";
	

	
	return 0;
}