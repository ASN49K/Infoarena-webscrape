#include <fstream>
int n, m, v1[1025], v2[1025], mat[1025][1025], sir[1025],ind;

using namespace std;

fstream fin ("cmlsc.in",ios::in);
fstream fout("cmlsc.out",ios::out);



void citire(){
	fin>>n>>m;
	for (int i=1;i<=n;i++)
		fin>>v1[i];
	for (int i=1;i<=m;i++)
		fin>>v2[i];
}

void calculare(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (v1[i]==v2[j])	mat[i][j]=mat[i-1][j-1]+1;
			else{
				if (mat[i-1][j]>mat[i][j-1]) {mat[i][j]=mat[i-1][j];}
				else {mat[i][j]=mat[i][j-1];};
			
			}
		}
	}
	int i,j;
	ind=1;
	for(i=n, j=m;i;){
		if (v1[i]==v2[j]){
			sir[ind]=v1[i];
			i--;
			j--;
			ind++;
		}	else {if (mat[i-1][j]>mat[i][j-1])
		{i--;} else {j--;}
		};
	
	}
}

void afisare(){
	fout<<--ind<<endl;
	for (int i=ind; i;i--)
		fout<<sir[i]<<" ";
}

int main(){
	citire();
	calculare();
	afisare();
}
