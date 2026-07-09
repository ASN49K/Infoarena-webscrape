#include <fstream>
using std :: ifstream ;
using std :: ofstream ;
ifstream fin("euclid2.in") ;
ofstream fout("euclid2.out") ;
int main(){
                int n ;
                fin >> n ;
                for(;n > 0;n--){
                        int a , b ;
                        fin >> a >> b ;
                        fin.get() ;
                        while(b){
                                int r = a % b ;
                                a = b ;
                                b = r ;
                        }
                        fout << a << '\n' ;
                }
                fin.close() ;
                fout.close() ;
                return 0 ;
}
