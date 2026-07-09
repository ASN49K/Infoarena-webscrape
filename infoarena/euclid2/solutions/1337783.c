#include<stdlib.h>
#include<stdio.h>
int main(){
    int t,b,a;
    int i;
    FILE *f;
    f=fopen("euclid2.in","r");
    fscanf(f,"%d",&t);
    int *buffer;
    buffer=(int*)malloc(sizeof(int)*2*t);
    int j=0;
    for(i=0;i<t;i++){
            fscanf(f,"%d",&(buffer[j]));
            fscanf(f,"%d",&(buffer[j+1]));
            j=j+2;
            }
    int q=0;
    
    for(i=0;i<t;i++){
            while (buffer[j]!=0){
                 if(buffer[j+1]>buffer[j]){
                          buffer[j]=buffer[j]+buffer[j+1];
                          buffer[j+1]=buffer[j]-buffer[j+1];
                          buffer[j]=buffer[j]-buffer[j+1];
                  }
                  if(buffer[j]%buffer[j+1]==0)buffer[j]=0;
                  else buffer[j]=buffer[j]%buffer[j+1];
            }
            buffer[q]=buffer[j+1];
            j=j+2;
            q++;
    }
    fclose(f);
    FILE *fp;
    fp=fopen("euclid2.out","w");
    for(i=0;i<t;i++){
            fprintf(fp,"%d\n",buffer[i]);
    }
    fclose(fp);
    free(buffer);
    return 0;
}
