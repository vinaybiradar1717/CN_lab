#include<stdio.h>

void dijk(int n,int s,int cost[10][10],int dist[10]){
    int i,u,visited[10],min,count=0;
    printf("HELO");
    for(i=1;i<=n;i++){
        visited[i]=0;
        dist[i]=cost[s][i];
    }
    count = 2;
    while(count<n){
        min=99;
        for(i=1;i<=n;i++){
            if(dist[i]<min && !visited[i]){
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;
        count++;
        for(i=1;i<=n;i++){
           if(dist[u]+cost[u][i]<dist[i] && !visited[i]){
               dist[i] = dist[u]+cost[u][i];
           } 
        }
    }
}


int main(){
    int n,i,j,s,cost[10][10],dist[10];
    printf("Enter number of nodes\n");
    scanf("%d",&n);
    printf("Enter the cost matrix\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    printf("Enter source node\n");
    scanf("%d",&s);
    dijk(n,s,cost,dist);
    printf("final result\n");
    for(i=1;i<=n;i++){
        if(i!=s){
            printf("%d--->%d, cost is %d \n",s,i,dist[i]);
        }
    }
}