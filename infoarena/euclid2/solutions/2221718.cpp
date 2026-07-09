#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in;
    in.open("euclid2.in");
    ofstream out;
    out.open("euclid2.out");
    int k,i;
    in >>k;
    int n,m;
    for(i = 0; i!= k ; i++){
        in >> n>>m;
        while (n != m){
            if(n>m) n = n-m;
            else m=m-n;
        }
        out <<n<<endl;
    }
    return 0;
}
