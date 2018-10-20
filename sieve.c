#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "sieve.h"

int siv_of_E(int n){
    int size=(int)(n*log((double)n)*1.15);
    char * bucket=calloc(size,sizeof(char *));
    int count=1;
    for(int i=3;i<size;i+=2){
        if(!bucket[i]){
            //printf("Prime %d : %d\n",count,i);
            count++;
            if(count==n){
                return i;
            }
            if(i<(n/10)){
                for(int j=i*3;j<size;j+=i){
                    if(!bucket[j]&&j%i==0){
                        bucket[j]=1;
                    }
                }
            }
        }        
    }
}
int main(){
    printf("%d\n",siv_of_E(1000000));
}