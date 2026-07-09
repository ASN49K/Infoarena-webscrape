#include <iostream>
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;

int T;
int a[100000] , b[100000];
int d = 1;

void Rezolvare()
{
    int aux = 2;

    fout.open("euclid2.out");
    fin.open("euclid2.in");
    fin >> T;

    for(int i = 0 ; i < T ; i++){
        fin >> a[i] >> b[i];
        while(aux <= min(a[i],b[i])){
            if(a[i] % aux == 0 && b[i] % aux == 0){
                d = aux;
            }
            aux++;
        }
        fout << d << "\n";

        d = 1;
        aux = 2;
    }
    fin.close();
    fout.close();
}

int main()
{
    Rezolvare();
    return 0;
}
