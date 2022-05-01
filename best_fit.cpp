#include<stdio.h>
struct slist
{
 int data;
 struct slist *next;
}*top,*temp,*start,*neww,temp1;
int bestfit(int n,int c)
{
 int res=0;
 int bin_rem[n],j;
 temp=start;
 while(temp->next!=NULL)
 {
 int min=c+1,bi=0;
 for(j=0;j<res;j++)
 {
 if(bin_rem[j]>=temp->data && bin_rem[j]-temp->data<min)
 {
 bi=j;
 min=bin_rem[j]-temp->data;
 }
 }
 if(min==c+1)
 {
 bin_rem[bi]=c-temp->data;
 res++;
 }
 else
 bin_rem[bi]=temp->data;
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
 int n=sizeof(weight)/sizeof(weight[0]);
 ans=bestfit(n,c);
 printf("No. of bins required in best fit : %d",ans);
 return 0;
}

//bins required: 3
//execution time: 0.024s
