#include "sieve.h"


/*int sieve(int n){
    int size;
    if(n<1000){
        size=n*10;
    }
    else{
        size=(int)(n*log((double)n)*1.15)/2;
    }
    int count=0;
    int * bucket=calloc(size/32,sizeof(int));
    int start=3;
    int ind=0;
    for(;start<=(int)sqrt(2*size);start+=2){
        if(!(bucket[ind/32]&1 << ind%32)){
                for(int j=ind+start+start;j<size;j+=start){
                    bucket[j/32]|= 1 << j%32;
                }
        }
        ind++;        
    }
    start=3;
    for(int i=0;i<size;i++){
        if(!(bucket[i/32]&1 << i%32)){
            count++;
        }
        if(count==n){
            return start;
        }
        start+=2;
    }
}*/

int sieve(int n){
    int size;
    if(n<1000){
        size=n*10;
    }
    else{
        size=(int)(n*log((double)n)*1.15);
    }
    if(n==1){
        return 2;
    }
    char * bucket=calloc(size,sizeof(char *));
    int count=1;
    for(int i=3;i<size;i+=2){
        if(!bucket[i]){
            //printf("Prime %d : %d\n",count,i);
            count++;
            if(count==n){
                return i;
            }
            if(i*i>0){
                for(int j=i*i;j<size;j+=i){
                    if(!bucket[j]&&j%i==0){
                        bucket[j]=1;
                    }
                }
            }
        }        
    }
}
