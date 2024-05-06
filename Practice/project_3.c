#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

//******Function Prototype******
void checkVowelOrConsonant(char a);

int main() {
   int *ptr;
   char c;
   
   ptr = (char *) malloc(sizeof(char));
   
   printf("Enter an alphabet: ");
   scanf("%c", &c);
   
   if (!isalpha(c)){
   		printf("Error! Non-alphabetic character.\n\n");
   		printf("Enter an alphabet: ");
   		scanf("%c", &c);
   	}
   	while(!isalpha(c)){
   		printf("Error! Non-alphabetic character.\n\n");
   		printf("Enter an alphabet: ");
   		scanf("%c", &c);
   	}
   	checkVowelOrConsonant(c);
   	free(ptr);

   return 0;
}

//******Function Definition******
void checkVowelOrConsonant(char a){
	int lowercase_vowel, uppercase_vowel;
	
	// evaluates to 1 if variable c is a lowercase vowel
   lowercase_vowel = (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');

   // evaluates to 1 if variable c is a uppercase vowel
   uppercase_vowel = (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U');

   // Show error message if c is not an alphabet
   if (lowercase_vowel || uppercase_vowel)
      printf("%c is a vowel.", a);
   else
      printf("%c is a consonant.", a);
}
