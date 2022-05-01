#include<stdio.h>
struct slist
{
 int data;
 struct slist *next;
}*top,*temp,*neww,*start;
int nextfit(int n,int c)
{
 int res=0,bin_rem=c;
 temp=start;
 while(temp->next!=NULL)
 {
 if(temp->data>bin_rem)
 {
 res++;
 bin_rem=c-temp->data;
 }
 else
 bin_rem-=temp->data;
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
 int c=10,ans; // c is bin capacity
 int n=sizeof(weight)/sizeof(weight[0]);
 ans=nextfit(n,c);
 printf("No. of bins required in next fit : %d",ans);
 return 0;
} 

//bins required: 3
//execution time: 0.040s
