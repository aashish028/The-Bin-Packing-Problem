#include<stdio.h>
struct slist
{
 int data;
 struct slist *next;
}*top,*temp,*neww,*start;
int firstfit(int n, int c)
{
 int res=0,bin_rem[n],i,j;
 temp=start;
 while(temp->next!=NULL)
 {
 for(j=0;j<res;j++)
 {
 if(bin_rem[j]>=temp->data)
 {
 bin_rem[j]=bin_rem[j]-temp->data;
 break;
 }
 }
 if(j==res)
 {
 bin_rem[res]=c-temp->data;
 res++;
 }
 temp=temp->next;
 }
 return res;
}
int main()
{
 int weight[]={2,5,4,7,1,3,8},i;
 for(i=0;i<sizeof(weight)/sizeof(weight[0]);i++)
 {
 neww=malloc(sizeof(struct slist));
 neww->data=weight[i];
 neww->next=NULL;
 if (i==0)
 {
 start=neww;
 top=neww;
 }
 else
 {
 top->next=neww;
 top=neww;
 }
 }
 int c=10,ans;
 int n = sizeof(weight)/sizeof(weight[0]);
 ans=firstfit(n,c);
 printf("No. of bins required in first fit : %d",ans);
 return 0;
} 

//no of bins required: 3
//the execution time was .032s
