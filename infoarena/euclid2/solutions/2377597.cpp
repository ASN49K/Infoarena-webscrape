
#include<fstream>

using namespace std;

int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");

    int n,a,b,r;
    cin>>n;
    for(;n;n--){
        cin>>a>>b;
        while(b){

            r = a%b;
            a=b;
            b=r;

        }
        cout<<a<<'\n';


    }


    return 0;
}
