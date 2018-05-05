/* Name: Ashley Fong
 * CS 362-400
 * Random Testing (RT) Quiz
 * Notes: Skeleton code provided. Functions edited include inputChar() and 
 * inputString(). Added '\n' to the "error" printf statement to make it clearer
 * to see when testing.
 * Citations:
 * rand() range: https://stackoverflow.com/questions/1202687/how-do-i-get-a-specific-range-of-numbers-from-rand
 * 'static char': discussion from #362 Slack channel
 * */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    	// input pool: characters in the ASCII code
    	// range: [32 .. 125]
    	char returnChar = (rand() % (125 + 1 - 32) + 32);
    	return returnChar;
}

char *inputString()
{
	
    	// input pool: only the letters used in the target statement
	char c1 = 'r';
	char c2 = 'e';
	char c3 = 's';
	char c4 = 'e';
	char c5 = 't';
	char c6 = '\0';

	static char returnString[6];

	int i;
	int stringSize = 5;
	int num;

	for (i = 0; i < stringSize; i++) {

	num = (rand() % (6 + 1 - 1) + 1);

	if (num == 1) {
		returnString[i] = c1;
	}

	if (num == 2) {
		returnString[i] = c2;
	}

	if (num == 3) {
		returnString[i] = c3;
	}

	if (num == 4) {
		returnString[i] = c4;
	}

	if (num == 5) {
		returnString[i] = c5; 
	}

	if (num == 6) {
		returnString [i] = c6;
	}


	}

	return returnString;

}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error \n");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
