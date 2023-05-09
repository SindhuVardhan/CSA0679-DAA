#include<stdio.h>
int fact(int x){
	int a;
	a=1;
	while(x>0){
		a=a*x;
		x--;
	}
	return(a);
}
int main(){

int s,r,n;
printf("enter the coeff of n and r:");
scanf(" %d %d",&n,&r);
s=fact(n)/fact(r)*fact(n-r);
printf("values is:%d",s);
}