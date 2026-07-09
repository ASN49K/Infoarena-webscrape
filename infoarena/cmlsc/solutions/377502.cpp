#include <fstream>

using namespace std;

const char InFile[]="cmlsc.in";
const char OutFile[]="cmlsc.out";
const int Max=1024;

int MAX2(int a, int b){
	if(a>b){return b;}else{return a;}
}

int m,n,a[Max],b[Max],d[Max][Max],sir[Max],len;

int main(void)
{
	ifstream fin(InFile);
    fin>>m>>n;
    for(register int i=1;i<=m;++i){
        fin>>a[i];
	}
    for(register int i=1;i<=n;++i){
        fin>>b[i];
	}
	fin.close();
		
    for(register int i=1;i<=m;++i){
        for(register int j=1;j<=n;++j){
            if(a[i]==b[j]){
                d[i][j]=1+d[i-1][j-1];
            }else{
                d[i][j]=MAX2(d[i-1][j],d[i][j-1]);
			}
		}
	}

    for(register int i=m,j=n;i>0;){
        if (a[i]==b[j]){
            sir[++len]=a[i];
			--i;
			--j;
        }else if (d[i-1][j]<d[i][j-1]){
            --j;
        }else{
            --i;
		}
	}

	ofstream fout(OutFile);
    fout<<len<<"\n";
    for(register int i=len;i>0;--i){
        fout<<sir[i]<<" ";
	}
	fout.close();
    return 0;
}


