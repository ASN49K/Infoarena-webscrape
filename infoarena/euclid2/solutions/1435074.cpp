#include <iostream>
#include <fstream>
using namespace std;


ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");


int euclid (int a ,int b ){
  if(b ==0 ){
    b = a;
  }
  else euclid(b,a%b);
}
int main()
{
    int T ;
    fin >> T;
    int a,b;
    for(int i = 0 ; i < T ; i++){


        fin >> a >> b;
        fout << euclid(a,b) << "\n";

    }

    return 0;
}
