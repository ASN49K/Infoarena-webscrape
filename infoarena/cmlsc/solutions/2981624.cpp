#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n, m, b; //b reprezinta al doilea sir scurtat
int vec1[100000], vec2[100000];
int din[100000]; // vector de adiacenta pentru vec2
int final[10000]; // sirul final
int cont; // contorul final



bool verif(int a){
	for(int i=1;i<=n;i++)
		if(vec1[i]==a)
			return 1;
	return 0;

}

void sir(){
int mare=0;
int loc=0;
	for(int i=1;i<=b;i++){
		for(int j=i-1;j>=1;j--){
			if(vec2[i]>=vec2[j]){
				din[i]++;
				if(mare<din[i]){
				mare=din[i];
				loc=i;
				}
			}
		}

	}

//int mare=0; // care este cel mai mare numar din vectorul de adiacenta
//int loc=0;
//for(int i=1;i<=b;i++){
//	if(din[i]>=mare){
//		mare=din[i];
//		loc=i;
//		}
//}
// s-ar putea sa fie o problema cand este 1 1 2 1 4 6 6 , nu stiu care 6 trebuie luat
for(int i=b;i>=1;i--){
	if(din[i]==mare){
		mare--;
		final[++cont]=vec2[i];
}
}



}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> vec1[i];

	while(m){
		int a;
		cin >> a;
		if(verif(a)==1)
			vec2[++b]=a;
		m--;
	}
//for(int i=1;i<=b;i++)
//	cout << vec2[i]<<' ';
//return 0;


sir();
cout << cont<<'\n';
for(int i=cont;i>=1;i--)
	cout << final[i]<<' ';

}
