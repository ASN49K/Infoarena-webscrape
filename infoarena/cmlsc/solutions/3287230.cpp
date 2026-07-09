#include <stdio.h>
using namespace std;
//https://www.youtube-nocookie.com/embed/BysNXJHzCEs?feature=oembed

int a,b,A[1025],B[1025],d[1025][1025],ind,sir[1025];

int maxim(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}

int main(){
    //metod  neortodoxa
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d%d",&a,&b);

    for(int i=1;i<=a;i++)
        scanf("%d",&A[i]);
    
    for(int i=1;i<=b;i++)
        scanf("%d",&B[i]);
    //facem matricea dinamica (dp)
    //formula
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){          
            if(A[i]==B[j]){                    
                d[i][j]=d[i-1][j-1]+1;
            }else
                d[i][j]=maxim(d[i-1][j],d[i][j-1]);  //de ce facem maximul?pt ca vrem secventa maxima si ne uitam la restu daca sunt mai mari ca sa putem continua               
        }
    }
    //reconstruim subsirul maxim (asta cere in problema)
    for(int i=a,j=b;i;){  //marimea matricei; echivalent while(i);    bucla se opreste cand completam de parcurs secventa A
        if(A[i]==B[j]){
            sir[++ind]=A[i];
            i--;
            j--;
        }else if(d[i-1][j]<d[i][j-1]){  //verificam de unde a venit valoarea optima
            j--;//prin ignorarea elementului curent din B
        }else
            i--;//prin ignorarea elementului curent din A
    }
    //in sir vom aveam 8,7 pt ca luam matricea din coltul dreapta jos i=a,j=b;
    printf("%d\n",ind);
    for(int i=ind;i;i--)
        printf("%d ",sir[i]);
}