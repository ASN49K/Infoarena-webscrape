#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    unsigned int t, a, b, r;
    fin >> t;
    while(t){
        fin >> a >> b;
        if(a < b){
	    r = a;
            a = b;
            b = r;
        }
        do{
            r = a % b;
            a = b;
            b = r;
        }while(r);
        fout << a << '\n';
        t--;
    }
    return 0;
}