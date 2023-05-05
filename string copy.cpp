# include <stdio.h>
# include <string.h>
int main(){
	char s1[]="hello";
	char s2[20];
	strcpy(s2,s1);
	printf("destination string is %s",s2);
	return 0;
}