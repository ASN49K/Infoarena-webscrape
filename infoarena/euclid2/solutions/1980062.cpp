#include <iostream>

#include <fstream>

#define input "euclid2.in"

#define output "euclid2.out"

using namespace std;

 

ifstream fin(input);

ofstream fout(output);

 

int cmmdc(int a,int b)

{

    if(!b)return a;

    else return cmmdc(b,a%b);

}

 

 

int main()

{

    int t,a,b;

    cin>>t;

    for( ; t;--t)

    {

        cin>>a>>b;

        cout<<cmmdc(a,b)<<'\n';

    }

    return 0;

}

