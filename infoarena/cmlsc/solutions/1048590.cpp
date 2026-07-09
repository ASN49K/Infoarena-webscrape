#include<fstream>
using namespace std;

void read(ifstream &in, int a[], int length) {
	for(int i=0;i<length;++i)
		in >> a[i];
}

int main(int argc, char* argv[]) {
	ifstream in;
	ofstream out;

	in.open("cmlsc.in");
	out.open("cmlsc.out");

	int m,n;
	in >> m >> n;

	int a[m];
	int b[n];

	read(in, a, m);
	read(in, b, n);

	int mat[m][n];

	for(int i=0;i<n;++i) {
		if(a[0] == b[i])
			mat[0][i] = 1;
		else
			mat[0][i] = (int)((i>0)?mat[0][i-1]:0);
	}
	for(int i=0;i<m;++i) {
		if(a[i] == b[0])
			mat[i][0] = 1;
		else
			mat[i][0] = (int)((i>0)?mat[i-1][0]:0);
	}

	for(int i=1;i<m;++i) {
		for(int j=1;j<n;++j) {
			if(a[i] == b[j])
				mat[i][j] = 1 + mat[i-1][j-1];
			else {
				if(mat[i-1][j] > mat[i][j-1])
					mat[i][j] = mat[i-1][j];
				else
					mat[i][j] = mat[i][j-1];
			}
		}
	}

	out << mat[m-1][n-1] << "\n";
	int poz = mat[m-1][n-1];
	int res[poz];
	int i = m-1;
	int j = n-1;

	while(poz > 0 && i >= 0 && j >= 0) {
		if(a[i] == b[j]) {
			res[--poz] = a[i];
			--i;
			--j;
		}
		else {
			if(i > 0 && j > 0) {
				if(mat[i-1][j] > mat[i][j-1])
					--i;
				else
					--j;
			}
			else {
				if(i == 0)
					--j;
				else
					--i;
			}
		}
	}	

	for(int i=0; i < mat[m-1][n-1]; ++i)  
		out << res[i] << " ";
	out <<"\n";

	out.close();
	in.close();
	return 0;
}

