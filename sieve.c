#include "sieve.h"

void bitchange(int * bitarray,int bitindex){
    int bit=bitindex%32;
    int index=bitindex/32;
    int final=1 << bit;
    bitarray[index]= bitarray[index]|final;
}
int bitcmp(int * bitarray,int bitindex ){
    int bit=bitindex%32;
    int index=bitindex/32;
    int final=1 << bit;
    return bitarray[index]&final;
}
int siv_of_E(int n){
    int size;
    if(n<1000){
        size=n*10;
    }
    else{
        size=(int)(n*log((double)n)*1.15);
    }
    int * bucket=calloc((size/32)+1,sizeof(int *));
    int count=1;
    for(int i=3;i<size;i+=2){
        if(!bitcmp(bucket,i)){
            //printf("Prime %d : %d\n",count,i);
            count++;
            if(count==n){
                free(bucket);
                return i;
            }
            if(n<100||i<(n/10)){
                for(int j=i*3;j<size;j+=i){
                    if(!bitcmp(bucket,j)&&j%i==0){
                        bitchange(bucket,j);
                    }
                }
            }
        }        
    }
}
