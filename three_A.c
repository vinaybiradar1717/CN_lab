#include<stdio.h>

struct node
{
    unsigned dist[10];
    unsigned from[10];
}rt[10];


int main(){
    int costmat[10][10], n,i,j,k,count=0;
    printf("Enter number of n\n");
    scanf("%d",&n);
    printf("Enter cost mastrix\n");
    // for(i=0;i<n;i++){
    //     for(j=0;j<n;j++){
    //         scanf("%d",&costmat[i][j]);
    //         costmat[i][i] = 0;
    //         rt[i].dist[j] = costmat[i][j];
    //         rt[i].from[j] = j;
    //     }
    // }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&costmat[i][j]);
            costmat[i][i]=0;
            rt[i].dist[j]=costmat[i][j];
            rt[i].from[j]=j;
        }
    }
    do{
        count = 0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j]){
                        rt[i].dist[j] = rt[i].dist[k]+rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
                }
            }
        }
    }while(count!=0);

    for(i=0;i<n;i++){
        printf("for node %d\n",i+1);
        for(j=0;j<n;j++){
            printf("node %d via %d, distance = %d\n",j+1,rt[i].from[j]+1,rt[i].dist[j]);
        }
    }
    printf("\n\n");
}