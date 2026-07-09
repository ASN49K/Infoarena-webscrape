#include <algorithm>
#define input "cmlsc.in"
#define output "cmlsc.out"
#define DIM 1030

using namespace std ;

int n , m , nr ;
int a[DIM][DIM] ;
int v[DIM] ;
int h ;

int maxim(int A , int B)
    {
        if (A>B)
            return A ;
        return B ;    
    }

void read()
    {
        scanf ("%d%d" , &n , &m) ;
        for (int i=1 ; i<=n ; i++)
            {
                scanf ("%d" , &nr) ;    
                a[i][0]=nr ;
            }
        for (int i=1 ; i<=m ; i++)
            {
                scanf ("%d" , &nr) ;
                a[0][i]=nr ;    
            }
    }
void solve()
    {
        for (int i=n ; i>=1 ; i--)
            {
                for (int j=m ; j>=1 ; j--)
                    {
                        if (a[0][j]==a[i][0])
                            a[i][j]=a[i+1][j+1]+1 ;
                        else
                            a[i][j]=maxim(a[i+1][j],a[i][j+1]) ;
                    }    
            }
        int sol=a[1][1] ;
        printf ("%d\n" , sol) ;
        for (int i=1 ; i<=n ; i++)
            {
                for (int j=1 ; j<=m ; j++)
                    {
                        if (a[i][j]==sol && a[0][j]==a[i][0])
                            {
                                sol-- ;
                                printf ("%d " , a[i][0]) ;
                            }   
                    }            
            }
    }
    
    
int main()
{
    freopen (input,"r",stdin) ;    
    freopen (output,"w",stdout);
    
    read() ;
    solve() ;
    
    return 0;
}
