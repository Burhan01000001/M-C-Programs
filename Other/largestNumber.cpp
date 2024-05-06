#include<iostream>
using namespace std;

int main()
{
	
	int array[3]={4,8,3};
	
	if(array[0]>array[1]&&array[0]>array[2]){
		cout<<array[0]<<" at index 0 is the largest number.";
	}
	else if(array[1]>array[0]&&array[1]>array[2]){
		cout<<array[1]<<" at index 1 is the largest number.";
	}
	else{
		cout<<array[2]<<" at index 2 is the largest number.";
	}
	
	return 0;
}	
