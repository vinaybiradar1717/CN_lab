#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y)(x>y)?y:x

int main()
{
    int buk,count=0,drop=0,output,input[10]={0},x,ch,i=0,nsec;
    printf("Enter bucket size\n");
    scanf("%d",&buk);
    printf("Enter output rate\n");
    scanf("%d",&output);

    do{
        printf("Enter number of packets entering in %d second ",i+1);
        scanf("%d",&input[i]);
        i++;
        printf("Enter 1 to continue and 0 to discontinue");
        scanf("%d",&ch);
    }while(ch);

    nsec = i;
    printf("seconds\tSent\tReceived\tDropper\tRemained\n");

    for(i=0; count || i< nsec ; i++){
        printf("%d",i+1);
        printf("\t%d",input[i]);
        printf("\t%d",MIN(input[i]+count,output));
        if((x = input[i]+count-output) > 0){
            if(x > buk){
                count = buk;
                drop = x-buk; 
            } else {
                count = x;
                drop = 0; 
            }
        } else {
            count = 0;
            drop = 0;
        }
        printf("\t%d\t%d\n",drop,count);
    }
    return 0;
}