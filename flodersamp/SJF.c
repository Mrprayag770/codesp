#include<stdio.h>

# define max 30
void main(){
         int i,j,n,t,p[max],bt[max],wt[max],tat[max];
         float awt=0,atat=0;
         printf("enter the no. of process");
         scanf("%d",&n);
         printf("Eneter the process num");
         for(i=0;i<n;i++){
         scanf("%d",&p[i]);
         
         }
         printf("enter the burst time");
         for(i=0;i<n;i++){
         scanf("%d",&bt[i]);
         
         }
         
         //sorting burst time
         for(i=0;i<n;i++){
         for(j=0;j<n-i-1;j++){
         if(bt[j]>bt[j+1]){
         t=bt[j];
         bt[j]=bt[j+1];
         bt[j+1]=t;
         
         t=p[j];
         p[j]=p[j+1];
         p[j+1]=t;
         };
}
}


printf("process \t burst time \t waiting time \t TAT \n");

for(i=0;i<n;i++){
  wt[i]=0;
  tat[i]=0;
  for(j=0;j<i;j++){
    wt[i]=wt[i]+bt[j];
  }
  tat[i]=wt[i]+bt[i];
  awt=awt+wt[i];
  atat=atat+tat[i];
  printf("%d\t %d\t\t %d\t\t %d\n",p[i],bt[i],wt[i],tat[i]);
  
  }
  awt=awt/n;
  atat=atat/n;
  printf("average wt %f\n",awt);
  printf("average tat %f\n",atat);
  
   
  }
