#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a,b;

    ifstream fin ("cmmdc.in");
    ofstream fout ("cmmdc.out");

    fin >> a;
    fin >> b;

    while(a != b){
        if(a > b){
            a-=b;
        }
        else{
            b -= a;
        }
    }
    if(a == 1){
        fout<< 0<< "\n";
    }
    else{
        fout<< a << "\n";
    }
    return 0;
}
