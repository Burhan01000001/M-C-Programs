#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

struct customer{
	char firstName[15];
	char lastName[15];
	char fatherName[15];
	int age;
	char phnNo[13];
	char email[25];
	char dateOfBirth[15];
	char address[100];
};

struct customer_CNIC{
	char CNIC_Name[15];
	char CNIC_Number[13];
	char CNIC_issueDate[15];
	char CNIC_expiryDate[15];
	char CNIC_address[100];
};

// Funtion to check that CNIC number is valid or invalid

void CNICvalidityCheck(char CNICnum[]){
	if(strlen(CNICnum)<13||strlen(CNICnum)>13){
		while(strlen(CNICnum)<13||strlen(CNICnum)>13){
			printf("Enter A Valid CNIC Number: ");
			scanf("%s",CNICnum);
		}
	}
}

// Funtion to check that phone number is valid or invalid

void phoneNumberValidityCheck(char phnNum[]){
	struct customer user_1;
	
	if(user_1.phnNo[0]!='+'){
		while(user_1.phnNo[0]!='+'){
			printf("Enter A Valid Phone Number: ");
			scanf("%s",&user_1.phnNo);
		}
	}
	
	if(user_1.phnNo[1]!='9'){
		while(user_1.phnNo[1]!='9'){
			printf("Enter A Valid Phone Number: ");
			scanf("%s",&user_1.phnNo);
		}
	}
	
	if(user_1.phnNo[2]!='2'){
		while(user_1.phnNo[2]!='2'){
			printf("Enter A Valid Phone Number: ");
			scanf("%s",&user_1.phnNo);
		}
	}
}

// Funtion to get some important details from the user

void customerDetails(){

	struct customer user_1;
	char* ptr;
	
	ptr = (char*) malloc(sizeof(user_1.firstName));
	printf("\n\nEnter Your First Name: ");
	scanf("%s", user_1.firstName);
	free(ptr);
	
	ptr = (char*) malloc(sizeof(user_1.lastName));
	printf("\nEnter Your Last Name: ");
	scanf("%s", user_1.lastName);
	free(ptr);
	
	ptr = (char*) malloc(15*sizeof(char));
	printf("\nEnter Your Father Name: ");
	scanf("%[^\n]", &user_1.fatherName);
	free(ptr);
	
	ptr = (int*) malloc(sizeof(int));
	printf("\nEnter Your Age: ");
	scanf("%d", &user_1.age);
	if(user_1.age<18){
		printf("You are younger than 18. You are not eligible \nto open a bank account.");
		exit(0);
	}
	
	ptr = (char*) malloc(13*sizeof(char));
	printf("\nEnter Your Phone Number: ");
	scanf("%s", &user_1.phnNo);
	phoneNumberValidityCheck(user_1.phnNo);
	free(ptr);
	
	ptr = (char*) malloc(25*sizeof(char));
	printf("\nEnter Your Email Address: ");
	scanf("%s", &user_1.email);
	free(ptr);
	
	ptr = (char*) malloc(15*sizeof(char));
	printf("\nEnter Your Date Of Birth: ");
	scanf("%[^\n]", &user_1.dateOfBirth);
	free(ptr);
	
	ptr = (char*) malloc(100*sizeof(char));
	printf("\nEnter Your Address: ");
	scanf("%[^\n]", &user_1.address);
	free(ptr);
		
}

// Funtion to get user CNIC details

void customerCNICdetails(){
	struct customer_CNIC user_1;
	char* ptr_2;
	
	ptr_2 = (char*) malloc(15*sizeof(char));
	printf("\n\nEnter Your Name: ");
	scanf("%[^\n]", &user_1.CNIC_Name);
	free(ptr_2);
	
	ptr_2 = (char*) malloc(13*sizeof(char));
	printf("\nEnter A Valid CNIC Number: ");
	scanf("%s",&user_1.CNIC_Number);
	CNICvalidityCheck(user_1.CNIC_Number);
	free(ptr_2);
	
	ptr_2 = (char*) malloc(15*sizeof(char));
	printf("\nEnter Your CNIC Issue Date: ");
	scanf("%[^\n]", &user_1.CNIC_issueDate);
	free(ptr_2);
	
	ptr_2 = (char*) malloc(15*sizeof(char));
	printf("\nEnter Your CNIC Expiry Date: ");
	scanf("%[^\n]", &user_1.CNIC_expiryDate);
	free(ptr_2);
	
	ptr_2 = (char*) malloc(100*sizeof(char));
	printf("\nEnter Your Address: ");
	scanf("%[^\n]", &user_1.CNIC_address);
	free(ptr_2);
	
}

int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generate_random_digits(char *str, int length) {
    for (int i = 0; i < length; i++) {
        str[i] = '0' + random_int(0, 9);
    }
    str[length] = '\0';
}

void customerAccountdetails(){
	srand(time(NULL)); // Seed the random number generator with current time

    // Generate random account number
    char account_number[10];
    generate_random_digits(account_number, 9);

    // Generate random IBAN number starting with "PK"
    char IBAN[30];
    IBAN[0] = 'P';
    IBAN[1] = 'K';
    generate_random_digits(IBAN + 2, 22);

    // Generate random CVV number
    char CVV[4];
    generate_random_digits(CVV, 3);

    // Get the current date
    time_t current_time = time(NULL);
    struct tm *current_date = localtime(&current_time);

    // Output the generated data in Pakistan format
    printf("******** Account Details ********\n\n");
    printf("Account Number: %s\n\n", account_number);
    printf("IBAN: %s\n\n", IBAN);
    printf("CVV: %s\n\n", CVV);
    printf("Issue Date: %02d-%02d-%d\n", current_date->tm_mday, current_date->tm_mon + 1, current_date->tm_year + 1900);
}

int main()
{

	printf("\n\t\tMeezan Bank - Account Opening System");
	
	printf("\n\n\n******** Enter Your Details ********");
	customerDetails();
	system("clear");
	
	printf("******** Enter Your CNIC Details ********");
	customerCNICdetails();
	system("clear");
	
	printf("Please!, Wait For Approval.....");
	sleep(5);
	system("clear");
	
	customerAccountdetails();
	
	return 0;
}
