#include <iostream>
#include <fstream>
using namespace std;



int cmmdc(int x, int y){

    while((x!=0) && (y!=0)){
        if (x > y) x=x % y;
        else y=y % x;
    }

return(x+y);

}

int main()
{
    int t,a,b;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin >> t;
    for(int i=0; i<t; i++){
        fin >> a >> b;
        fout<< cmmdc(a,b) <<"\n";
    }



    return 0;
}
