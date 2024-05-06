#include <stdio.h>
#include <stdlib.h>

struct name{
	char str[10];
};

int main()
{
	
	struct name user_name;
	char* ptr;
	
	ptr = (char*) malloc(10*sizeof(char));
	
	printf("Enter Your Name: ");
	gets(user_name.str);
	
	printf("%s",user_name.str);
	
	free(ptr);
	
	return 0;
}