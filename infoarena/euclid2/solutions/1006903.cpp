#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T, i, a, b;
int divcom(int a, int b){


    while(b!=0){


        if(a>b)
            a=a-b;


        else
            a=b-a;


    }
    return a;

}
int main(){
    fin>>T;


    for(i=1; i<T; i++)

        fin>>a;
        fin>>b;
        divcom(a, b);


    return 0;
}
