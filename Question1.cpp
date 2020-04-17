#include <stdio.h>
#include<stdlib.h>

int consumer_waiting=0;
int producer_waiting=0;
int size=5;
int showno=0;
int empty=5;
int full=0;
int in=0;
int out=0;
int chk=-10;

void show (int arr[],int r)
{
printf("\n\n _________________________________________________________");

if(showno==0)
printf("\nNOTHING TO SHOW ");
else
{ printf("\n |");
for (int n=0; n<showno; n++)
{printf("   %d   |",arr[r]);
r=(r+1)%size;
}}
printf("\n\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\n");
printf("\n NUMBER OF PRODUCER WATING ARE : %d        NUMBER OF CONSUMER WAITING ARE: %d", producer_waiting, consumer_waiting);
}

int semwait(int a)
{
if(a<0)
{a--;
chk=0;
return a;}
else {a--; chk=a; return a;}
}	

int semsignal(int a)
{
if(a<0)
{a++; chk=0;return a;}
else{ a++; chk=a; return a;}}

void consumer(int arr[], int c)
{int chk;int a=empty; int x=0; int h;  int l,m,n;

if(c>0)
{

{for(int i=0; i<c; i++)
{

if(full<=0)
{consumer_waiting++;printf("\n NOW %d CONSUMER WAITING...",consumer_waiting);}
else
{
full=semwait(full);
empty=semsignal(empty);
printf("\n CONSUMER GET THE VALUE: %d",arr[out]);
out=(out+1)%size;
showno--; show(arr,out);

if(producer_waiting >0)
{ l=producer_waiting;
while(showno!=size && producer_waiting!=0)
{printf("\n ONE PRODUCER FREE \n INSERT A VALUE FOR THAT FREE PRODUCER :");
scanf("%d",&h);
arr[in]=h;
in=(in+1)%size;
empty=semwait(empty);
full=semsignal(full);
showno++;
producer_waiting--;printf("\n %d PRODUCER WAITING",producer_waiting);
}
show(arr,out);
}
}
}//end for loopshow(arr,out);

}
}//if ends


printf("\n %d %d %d %d",in ,out ,empty ,full);
}	///consumer ends

void producer(int arr[], int p)
{int chk;int a=empty; int x=0; int h;  int l,m,n;
//printf("\n PRODUCER: %d \n \n ............................ \n",producer);
if(p>0)
{

{for(int i=0; i<p; i++)
{

if(empty<=0)
{producer_waiting++;printf("\n NOW %d PRODUCER WAITING...", producer_waiting);}
else
{printf("\n PRODUCER INSERT A VALUE:");
scanf("%d",&h);
arr[in]=h;
in=(in+1)%size;
empty=semwait(empty);
full=semsignal(full);
showno++;
show(arr,out);
if(consumer_waiting >0)
{ l=consumer_waiting;
while(showno!=0 && consumer_waiting!=0)
{full=semwait(full);
empty=semsignal(empty);
printf("\n ONE CONSUMER FREE WITH VALUE: %d",arr[out]);
out=(out+1)%size;
showno--;
consumer_waiting--;
printf("\n %d CONSUMER WAITING",consumer_waiting);

}
show(arr,out);
}
}
}//end for loopshow(arr,out);

}
}//if ends

}	///producer ends

void call(int arr[],int pc){
	int p=-1,c=-1; int l=-1;
	while(p<0 && pc==1)
	{printf("\nEnter Number of Producer:");
scanf("%d",&p); c=0;}
	while(c<0 && pc==2)
	{printf("\n Enter Number of Consumer:");
scanf("%d",&c);p=0;}
	while(p<0 && c<0 && pc==3)
	{printf("\nEnter Number of Producer:");
scanf("%d",&p);printf("\n Enter Number of Consumer:");
scanf("%d",&c);}
if(pc==4)show(arr,out);
if(pc!=3){
producer(arr,p);
consumer(arr,c);
}
if(pc==3){printf("\n ENTER 1 IF PRODUCER COME FIRST 2 IF CONSUMER:  ");
scanf("%d",&l);
if(l==1){producer(arr,p);consumer(arr,c);}
if(l==2){consumer(arr,c);producer(arr,p);} }
	}


int main(int argc, char** argv) {
	int pc=1,arr[5];
	arr[0]=0;int opt;
	while(pc!=0){
pc=0;
printf("\nENTER \n 1 TO ADD ONLY PRODUCER \n 2 FOR ONLY CONSUMER \n 3 TO ADD BOTH \n4 FOR DISPLAY \n 0 FOR EXIT:  ");
scanf("%d",&pc);
if(pc<0 || pc>3)
printf("\n INVALID OPTION PLEASE RE-ENTER");
call(arr,pc);}
printf("\n");
	return(0);
}
