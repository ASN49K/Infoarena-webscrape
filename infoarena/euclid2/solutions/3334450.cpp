#include <iostream>
#include<fstream>
using namespace std;


int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    
    int t;
    fin >> t;
    while(t--){
        int x,y;
        fin >> x >> y;
        while(y){
            int r = x%y;
            x = y;
            y = r;
        }
        fout << x << endl;
    }
    return 0;
}
