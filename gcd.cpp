#include <stdio.h>
int gcd(int a,int b){
	if(a==b){
		return a;
	}
	else{
		return gcd(b,a%b);
	}
}
int main(){
	int n1,n2,res;
	printf("enter two numbers:");
	scanf("%d %d",&n1,&n2);
	res=gcd(n1,n2);
	printf("gcd of %d and %d is %d:\n",n1,n2,res);
	return 0;
}