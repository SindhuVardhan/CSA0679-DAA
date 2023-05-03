#include <stdio.h>
int main(){
	int num,on,rem,res=0;
	printf("enter the number:");
	scanf("%d",&num);
	on=num;
	while(on!=0){
		rem=on%10;
		res+= rem*rem*rem;
		on /= 10;
		
	}
	if(res==num){
		printf("it is amstrong number",num);
}
	else{
		printf("not AN");
		return 0;
	}
	
	
}
