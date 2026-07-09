#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define MAXM 1024

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int N,M,a[MAXM],b[MAXM],d[MAXM],i,j,counter;
vector<int> el, sol,ant;

void cit(){
    in>>N>>M;
    for(i = 0 ; i < N; i ++){
        in>>a[i];
    }
    for(i = 0 ; i < M; i ++){
        in>>b[i];
    }
}
int best(int i) {

	counter = 1;
	for (int j = i + 1; j < N; j++) {
        ant.push_back(d[j-1]);
		if (d[i] < d[j] && ant[j-1] != d[j]) {
			el.push_back(d[j]);
			counter++;
			if (j == N - 1) {
				sol.push_back(counter);
				return counter;
			}
		}
	}
	sol.push_back(counter);
	return counter;
}
int PD(){
    counter = 0 ;
    for(i = 0 ; i < N; i ++){
        for(j = 0 ; j < M; j ++){
            if(a[i] == b[j]){
                d[counter] = a[i];
                counter ++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
		best(i);
	}

	int best_length = 0, poz = 0;
	for (int i = 0; i < N; i++) {

		if (sol[i] >= best_length) {
			best_length = sol[i];
			poz = i;
		}
	}
	out << best_length << endl << d[poz] << " ";
	sort(el.begin(), el.end());
	unique(el.begin(), el.end());
	for (int i = 0; i < best_length - 1; i++) {
		out << el[i] << " ";
	}

    return 0;
}

int main()
{
    cit();
    PD();
    return 0;
}
