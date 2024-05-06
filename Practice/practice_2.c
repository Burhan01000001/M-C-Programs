#include<stdio.h>

int main(){
    int n;
    printf("Enter length of array: ");
    scanf("%d",&n);
    printf("\n");
    
    int num[n], target;
    for(int i =1;i<=n;i++){
        printf("Enter a number: ");
        scanf("%d",&num[i]);
    }
    printf("\nEnter your target: ");
    scanf("%d",&target);
    
    
    for(int j =0;j<=n;j++){
        int k =1;
        if((num[i]+num[k])==target){
            
        }
    }
    
    return 0;
}
