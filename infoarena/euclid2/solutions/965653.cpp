#include <fstream>

using namespace std;

void work(ifstream &fin, ofstream &fout){
    int perechiDeNumere;
    int a, b;
    fin>>perechiDeNumere;
    for(int i = 1; i <= perechiDeNumere; i++){
        fin>>a>>b;
        int r;
        while(b){
            r = a%b;
            a = b;
            b = r;
        }
        fout<<a<<"\n";   //"endl" - 30pct , "\n" - 100pct
    }
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    work(fin, fout);
    fin.close();
    fout.close();
    return 0;
}
