#include <iostream> 
#include <fstream>
#include <stack>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int mat[1025][1025];
int vect[1025];
int vect2[1025];

int main()
{
    
    
    int n , m ;
    f >> n >> m ;
    int mats = 0 ;

    for(int i = 1 ; i <= n ; i++ ) { f >> vect[i] ; }
    for(int j = 1 ; j <= m ; j++ ) { f >> vect2[j] ; }

    mat[0][0] = 0 ;
    for(int i = 1 ; i <= n ; i++ ) { mat[i][0] = 0 ; }
    for(int j = 1 ; j <= m ; j++ ) { mat[0][j] = 0 ; }

    for(int i = 1 ; i <= n ; i++)
    {    
        for(int j = 1 ; j <= m ; j++ )
        {
            if(vect[i] == vect2[j]) 
            { 
                mat[i][j] = 1 + mat[i-1][j-1];
                    
            } else mat[i][j] = max(mat[i-1][j],mat[i][j-1]) ;
        }
        
    }

    g << mat[n][m] ;
    g << endl ;
    int i = n ; 
    int j = m ;
    int k = mat[n][m];
    int vect4[k+1];
    while(i>=1 && j>=1)
    {
        if(mat[i][j]<=mat[i-1][j]) i--;
        else if(mat[i][j]<=mat[i][j-1]) j--;
        else{
            vect4[k] = vect[i];
            k--;
            i--;
            j--;
        }

    }
    k = mat[n][m];
    for(int i = 1 ; i <= k ; i++ )
    {
        g << vect4[i] << " " ;
    }
    f.close();
    g.close();
    return 0;


  
}