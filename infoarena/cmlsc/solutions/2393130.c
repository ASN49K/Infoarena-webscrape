#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	if(a>b)
		return a;
	return b;
}
int main(int argc, char *argv[]){
	FILE *fs;
	int n,m;
	fs = fopen("cmlsc.in", "r");
	fscanf(fs,"%d",&n);
	fscanf(fs,"%d",&m);
	
	int v1[n];
	int v2[m];

	for(int i=0;i<n;i++){
		fscanf(fs,"%d",&v1[i]);
	}

	for(int i=0;i<m;i++){
		fscanf(fs,"%d",&v2[i]);
	}

	int dp[n+1][m+1];

	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			dp[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){

			if(v1[i-1]==v2[j-1]){

				dp[i][j]= dp[i-1][j-1]+1;
			}else{
				dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	/*for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", dp[n][m]);*/

	int i=n;
	int j=m;
	int sol[dp[n][m]];
	int currentIndex = dp[n][m] -1;

	while(currentIndex>=0){
		if((dp[i][j]==(dp[i-1][j-1]+1))&&(dp[i][j]!=max(dp[i][j-1],dp[i-1][j]))){
			sol[currentIndex] = v1[i-1];
			currentIndex--;
			i--;
			j--;
		}else{

			if(dp[i][j-1]==max(dp[i-1][j],dp[i][j-1])){
				j--;
			}else{
				i--;
			}
		}
		

	}
	/*for(int i=0;i<dp[n][m];i++){
		printf("%d ",sol[i] );
	}
	printf("\n");*/

	FILE * fp;
   /* open the file for writing*/
   fp = fopen ("cmlsc.out","w");
 
   fprintf (fp, "%d\n",dp[n][m]);
   /* write 10 lines of text into the file stream*/
   for(i = 0; i < dp[n][m];i++){
       fprintf (fp, "%d ",sol[i]);
   }
   fprintf(fp, "\n");
 
   /* close the file*/  
   fclose (fp);
   return 0;
}