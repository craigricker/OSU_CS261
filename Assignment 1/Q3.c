/* CS261- Assignment 1 - Q.3*/
/* Name: 
 * Date: 
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

#define ASCII_OFFSET 32
#define REPLACE_CHAR '_'
#define BUFFER_SIZE 80
int isLower(char ch){
   return ((ch >= 97) && (ch <= 122));
}

int isUpper(char ch){
   return ((ch >= 65) && (ch <= 90));
}


int isLetter(char ch) {
   if (isLower(ch) || isUpper(ch))
      return 1;
   else
      return 0;
}

char toUpperCase(char ch){
  /*Convert ch to upper case, assuming it is in lower case currently*/
   if (isUpper(ch))
      return ch;
   else
      return (ch - ASCII_OFFSET);
   
}

char toLowerCase(char ch){
  /*Convert ch to lower case, assuming it is in upper case currently*/                          
   if (isLower(ch))
      return ch;
   else
      return (ch + ASCII_OFFSET);
}

int stringLength(char s[]) {
   /*Return the length of the string*/
   int strLen = 0;
   for (char * curCh = s; (* curCh) != '\0'; curCh++) {
      strLen++;
   }
   return strLen;
}


void camelCase(char* word){
	/*Convert to camelCase*/
   int letterCount = 0;                      // Count # of letters
   int nonLetterCount = 0;                   // Count of non letters
   int wordLength = stringLength(word);      // Length of input word
   int digit;                                // Track current digit
   int prevLetter  = 0;                      // Check if previous was letter
   char buffer[BUFFER_SIZE];                  // Temporary buffer to store created output
   for (digit = 0; digit < wordLength; digit++) {
      if (isLetter((word[digit])))
         letterCount++;
      else
         nonLetterCount++;
   }
      // Decrement digit to see if it is a letter
   digit--;
   if (!nonLetterCount ||!letterCount || !isLetter((word[digit]))) {
      printf("invalid input string\n");
      return;
   }
   
   // Replace all non letter strings with _ as explained in assignment
   // ""_random_ _word" should be changed to "random_word" first."
   for (digit = 0; digit < wordLength; digit++) {
      if (isLetter((word[digit]))) {
         word[digit] = toLowerCase((word[digit]));
         prevLetter = 1;
      }
      else {
         word[digit] = REPLACE_CHAR;
         int offset = 1;
         while (!isLetter(word[digit+offset])) {
            digit++;
            offset++;
            wordLength--;
         }

      }
   }
   
   for (digit = 0; digit < wordLength; digit ++) {
      
   }
   
   
   
   

	
}

int main(){

	/*Read the string from the keyboard*/
   char input[BUFFER_SIZE];   // Container for user input
   printf("Please enter a value to be converted:");
   scanf("%s", input);
	/*Call camelCase*/
   camelCase(input);
   printf("%s\n", input);
	
	/*Print the new string*/
	
	
	return 0;
}

