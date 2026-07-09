    #include<stdio.h>  
      
    int cmmdc(int a,int b){  
        if(a==0) return b;  
        else if(b==0) return a;  
            else return cmmdc(b, a%b);  
     }  
  
   
   int main(){  
       int a,b,n,i;
	freopen("euclid2.in", "r" ,stdin);
	freopen("euclid2.out", "w" ,stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++){  
       scanf("%d %d",&a,&b);  
       printf("%d\n",cmmdc(a,b));
	}  
       return 0;  
       }  
