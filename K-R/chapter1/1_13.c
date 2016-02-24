/**************************
show the words Horizontal histogram
***************************/
#include <stdio.h>

#define IN 1		//in the word
#define OUT 0		//out the word
#define MAXLINE 20	//the numbers of the word
#define MAXLEN 20	//the max size of one word
main()
{
	char	arr[MAXLINE][MAXLEN];
	int		c, state, nw, i, j;

	nw = i = j = 0;
	state = OUT;

	//init the arr
	for (i = 0; i < MAXLINE; i++)
		for (j = 0; j < MAXLEN; j++)
			arr[i][j] = 0;

	i = j = 0;
	while ((c = getchar()) != EOF){
		if (c == ' ' | c == '\t' || c == '\n'){
			//one word
			if (state == IN){
				arr[i++][j++] = '\0';
				j = 0;
				nw++;
			}
			state = OUT;
		}
		//the first character of the word
		else if (state == OUT){
			arr[i][j++] = c;
			state = IN;
		}
		//the remaining character after the first character of the word
		else if (state == IN)
			arr[i][j++] = c;
	}

	//show the word Horizontal histogram
	for (i = 0; i < nw; i++){
		for (j = 0; arr[i][j] != '\0'; j++){
			putchar(arr[i][j]);
		}
		putchar(':');
		while (j--)
			putchar('*');
		putchar('\n');
	}
}