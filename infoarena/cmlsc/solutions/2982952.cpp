#include <fstream>
using namespace std;

#define maxim(a,b) ((a>b) ? a : b)

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n, m; //b reprezinta al doilea sir scurtat
int n2, m2;
int vin[100000]; // vectorul 1 de dinainte 
int vec1[100000], vec2[100000];
int din[100000]; // vector de adiacenta pentru vec2
int final[10000]; // sirul final
int cont; // contorul final
int mat[1004][1004];//??????



bool verif(int a){
	for(int i=1;i<=n;i++)
		if(vin[i]==a)
			return 1;
	return 0;

}



int main(){
	cin >> n2 >> m2;
	for(int i=1;i<=n2;i++)
		cin >> vec1[i];

    for(int i=1;i<=m2;i++)
        cin >> vec2[i];

	//while(m)
    //{
	//	int a;
	//	cin >> a;
	//	if(verif(a)==1)
	//		vec2[++m2]=a;
	//	m--;
	//}
    //for(int i=1;i<=n;i++)
    //{
    //    for(int j=1;j<=m2;j++)
    //    {
    //        if(vin[i]==vec2[j])
    //        {
    //            vec1[++n2]=vin[i];
    //            break;
    //        }
    //    }
    //}


    for(int i=1;i<=n2;i++){
        for(int j=1;j<=m2;j++){
            if(vec1[i]==vec2[j]){
                mat[i][j]=1+mat[i-1][j-1];
            }
            else
                mat[i][j]=maxim(mat[i-1][j], mat[i][j-1]);
        }
    }

    for(int i=n2;i>=1;i--){
        for(int j=m2;j>=1;j--){
            
        }
    }
    for(int i=n2, j=m2; i && j;){
        if(vec1[i]==vec2[j])
            final[++cont]=vec1[i] , --i, --j;
        else if(mat[i-1][j]<mat[i][j])
            j--;
        else
            i--;
    }


cout << cont<<'\n';
for(int i=cont;i>=1;i--)
	cout << final[i]<<' ';

}