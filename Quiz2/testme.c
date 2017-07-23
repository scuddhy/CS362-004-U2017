#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    	// TODO: rewrite this function
	char array[9] = {'[', '(', '{', ' ', 'a', 'x', '}', ')', ']'};
	
	int character = rand() % 9;
    	return array[character];
}

char *inputString()
{
    	// TODO: rewrite this function
	//initialize the array with a for loop
	int i;
	char choices[4] = {'r', 'e', 's', 't'};
	static char array[5];
	memset(array, '\0', (sizeof(char)* 5));
	
	//array[0] = 'r';
	//array[1] = 'e';
	//array[2] = 's';
	//array[3] = 'e';
	//array[4] = 't';




	for(i = 0; i < 5; i++){
		array[i] = choices[(rand() % 4)];
	}


	return array;
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
      printf("error ");
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
