#include "sieve.h"

void bitchange(int * bitarray,int bitindex){
    bitarray[bitindex/32]= bitarray[bitindex/32]|1 << bitindex%32;
}
int bitcmp(int * bitarray,int bitindex ){
    return bitarray[bitindex/32]&1 << bitindex%32;
}
int sieve(int n){
    int size;
    if(n<1000){
        size=n*10;
    }
    else{
        size=(int)(n*log((double)n)*1.15);
    }
    int * bucket=calloc((size/32),sizeof(char *));
    int count=1;
    for(int i=3;i<size;i+=2){
        if(!(bucket[i/32]&1 << i%32)){
            //printf("Prime %d : %d\n",count,i);
            count++;
            if(count==n){
                free(bucket);
                return i;
            }
            if(n<100||i<(n/10)){
                for(int j=i*i;j>0&&j<size;j+=i){
                    if(!(bucket[j/32]&1 << j%32)&&j%i==0){
                         bucket[j/32]= bucket[j/32]|1 << j%32;
                    }
                }
            }
        }        
    }
}

/*int sieve(int n){
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
            if(i*i>0&&i*i<size&&i<(n/10)){
                for(int j=i*i;j<size;j+=i){
                    if(!bucket[j]&&j%i==0){
                        bucket[j]=1;
                    }
                }
            }
        }        
    }
}*/
