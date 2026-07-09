#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAX = 1026;

int N , M;

//vector <int> LCS [ MAX ] ;
vector <vector <  vector <int>  > > LCS ;
vector <int>  sir1 , sir2;

void findLCS(){

    int i,j,x;


    for ( i = 1; i <= N ; i++)
        for ( j = 1 ;j <= M ;j++)
            if ( sir1 [i] == sir2 [j]){
                for ( x = 0 ; x < LCS [ i - 1] [ j - 1].size() ; x++)
                    LCS [ i ] [ j ].push_back(LCS [ i - 1] [ j - 1] [ x ]);
                    LCS [ i ] [ j ].push_back ( sir1 [ i ] );
            }

            else{
                if ( LCS [ i ] [ j - 1 ].size() > LCS [ i-1 ] [ j ].size() )
                  for ( x = 0 ; x < LCS [ i] [ j -1 ].size() ; x++){
                        LCS [ i ] [ j ].push_back(LCS [ i ] [ j-1 ] [ x ]);
                    }
                else
                  for ( x = 0 ; x < LCS [ i - 1 ] [ j ].size() ; x++){
                        LCS [ i ] [ j ].push_back(LCS [ i -1 ] [ j ] [ x ]);
                    }
            }


}

int main()
{
    ifstream f("cmlsc.in", ios::in);
    ofstream g("cmlsc.out", ios::out);
    f>>N>>M;


    LCS.resize(MAX);

    for ( int i = 0 ; i < MAX ; i++)
        LCS [ i ].resize(MAX);

    sir1.resize(0);
    sir2.resize(0);

    sir1.push_back(0);
    sir2.push_back(0);

    int cpyN = N , cpyM = M ,x;

    while (cpyN--){
        f>>x;
        sir1.push_back(x);
    }
    while (cpyM--){
        f>>x;              //
        sir2.push_back(x);
    }


    findLCS();

    g<<LCS[ N ] [ M ].size()<<"\n";
        for ( int i = 0 ; i < LCS[ N ] [ M ].size() ; i++)
            g<<LCS[ N ] [ M ] [ i ]<<" ";
    return 0;
}
