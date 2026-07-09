// https://www.infoarena.ro/problema/cmlsc

#include<fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int sirA[1025], sirB[1025];

// dp[indexA][indexB] = lungimea maxima a subsirului comun daca se iau in considerare doar primele indexA elemente din sirA si primele indexB elemente din sibB
// dp[0][indexB] = 0 (declarat global), adica nu avem subsir comun daca sirul A este gol
// dp[indexA][0] = 0 (declarat global), adica nu avem subsir comun daca sirul B este gol 
int dp[1025][1025];

// subsir va memora subsirul comun
int subsir[1025];

// lSubsir va memora lungima subsirului comun
// fiind declarat global, are valoarea 0 initial
int lSubsir;

int main() {
	fin >> n >> m;

	for(int i = 1; i <= n; i++) {
		fin >> sirA[i];
	}

	for(int i = 1; i <= m; i++) {
		fin >> sirB[i];
	}

	for(int indexA = 1; indexA <= n; indexA++) {
		for(int indexB = 1; indexB <= m; indexB++) {
			if(sirA[indexA] != sirB[indexB]) {
				// Elementele din cele doua siruri nu se potrivesc, deci nu ne ajuta sa ne prelungim subsirul comun.
				// Asadar, unul din cele doua elemente este irelevante pentru solutia optima.
				// Nu stim care asa ca verificam ambele variante (fie ignoram sirA[indexA], fie ignoram sirB[indexB]) si vedem ce lungime maxima obtinem.
				// Vom lua in considerare maximul dintre ele, pentru a obtine solutia optima.
				if(dp[indexA - 1][indexB] >= dp[indexA][indexB - 1]) {
					dp[indexA][indexB] = dp[indexA - 1][indexB];
				} else {
					dp[indexA][indexB] = dp[indexA][indexB - 1]; 
				}
			} else {
				// Elementele sunt egale.
				// Prin urmare lungimea subsirului comun obtinut pana acum (excluzand elementele sirA[indexA] si sirB[indexB]) creste cu o unitate
				dp[indexA][indexB] = dp[indexA - 1][indexB - 1] + 1;
			}
		}
	}

	// afisam lungimea maxima a subsirului comun atunci cand luam in considerare toate elementele din sirA si toate elementele din sirB
	fout << dp[n][m] << endl;

	int indexA = n, indexB = m;

	while(indexA >= 1 && indexB >= 1) {
		if(sirA[indexA] == sirB[indexB]) {
			// a fost o potrivre la indexA si indexB, deci elementul face parte din subsirul comun, asa ca il adaugam in vectorul subsir
			subsir[lSubsir] = sirA[indexA];
			lSubsir++;

			indexA--;
			indexB--;
		} else {
			// nu a fost potrivire
			// verificam cum am obtinut valoarea optima dp[indexA][indexB], ignorand sirA[indexA] sau sirB[indexB]
			if (dp[indexA - 1][indexB] >= dp[indexA][indexB - 1]) {
				indexA--;
			} else {
				indexB--;
			}
		}
	}

	// afisam vectorul subsir in ordine inversa, pentru a aparea elementele in ordinea in care apar ele in vectorii sirA, respectiv sirB
	for(int i = lSubsir - 1; i >= 0; i--) {
		fout << subsir[i] << " ";
	}

	fout << endl;

	fin.close();
	fout.close();

	return 0;
}
