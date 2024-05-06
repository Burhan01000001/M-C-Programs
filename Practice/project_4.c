//#include <stdio.h>

//int main()
//{
//	int value_1,value_2,value_3;
//	printf("Enter 3 Integer Numbers: ");
//	scanf("%d",&value_1);
//	scanf("%d",&value_2);
//	scanf("%d",&value_3);
	
//	if(value_1 > (value_2&&value_3)){
//		printf("%d is the greatest number.",value_1);
//	}
//	else if(value_2 > (value_1&& value_3)){
//		printf("%d is the greatest number.",value_2);
//	}
//	else if(value_3 > (value_1&&value_2)){
//		printf("%d is the greatest number.",value_3);
//	}
	
//	return 0;
// }

#include <stdio.h>

int main() {
    int value_1, value_2, value_3;
    printf("Enter 3 Integer Numbers: ");
    scanf("%d %d %d", &value_1,&value_2,&value_3);
    // scanf("%d", &value_2);
    // scanf("%d", &value_3);

    if (value_1 > value_2 && value_1 > value_3) {
        printf("%d is the greatest number.", value_1);
    } else if (value_2 > value_1 && value_2 > value_3) {
        printf("%d is the greatest number.", value_2);
    } else {
        printf("%d is the greatest number.", value_3);
    }

    return 0;
}
