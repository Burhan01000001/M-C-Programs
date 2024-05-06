#include <stdio.h>

int main() {
    int vowels, consonants, digits, whiteSpaces;
    
    vowels=0;
    consonants=0;
    digits=0;
    whiteSpaces=0;
    
    char str[100];
    printf("Enter A String: ");
    fgets(str, sizeof(str), stdin);
    
    for(int i =0;str[i]!='\0';++i){
    	if(str[i]==' '){
    		whiteSpaces++;
    	}
    	else if(str[i]=='a'&&'e'&&'i'&&'o'&&'u'){
    		vowels++;
    	}
    	else if(str[i]=='0'||'1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9'){
    		digits++;
    	}
    	else if(str[i]!='a'&&'e'&&'i'&&'o'&&'u'&&'0'||'1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9'){
    		consonants++;
    	}
    }
    
    printf("Digits = %d\n",digits);
    printf("Consonants = %d\n",consonants);
    printf("white Spaces = %d\n",whiteSpaces);
    printf("Vowels = %d",vowels);
    
    return 0;
}
