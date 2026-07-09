#include <fstream>

#define infile "cmlsc.in"
#define outfile "cmlsc.out"

using namespace std;

ifstream in(infile);
ofstream out(outfile);

int m, n;

short int a[1025];
short int b[1025];

int lungime[1025][1025];
short int sir[1025];


int main()
{
    in >> m >> n;

    for(int i=1; i<=m; i++){
        in >> a[i];
    }
    for(int i=1; i<=n; i++){
        in >> b[i];
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(a[i] == b[j]){
                lungime[i][j] = lungime[i-1][j-1] + 1;
            }else{
                lungime[i][j] = max(lungime[i-1][j], lungime[i][j-1]);
            }
        }
    }

    for(int i=m, j=n; lungime[i][j];){
        sir[lungime[i][j]] = a[i];
        if(a[i] == b[j]){
            i--;
            j--;
        }else{
            if(lungime[i-1][j] >= lungime[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }

    out << lungime[m][n] << '\n';

    for(int i=1; i<=lungime[m][n]; i++){
        out << sir[i] << ' ';
    }

    return 0;
}
