/*********************
show the word Vertical histogram
*********************/
#include <stdio.h>

#define IN 1		//in the word
#define OUT 0		//out the word
#define MAXLINE 20	//the numbers of the word
#define MAXLEN 20	//the max size of one word
main()
{
	char	arr[MAXLINE][MAXLEN];
	int		c, state, nw, i, j, maxLen, tempMaxLen;

	nw = i = j = maxLen = tempMaxLen = 0;
	state = OUT;

	//init the arr
	for (i = 0; i < MAXLINE; i++)
		for (j = 0; j < MAXLEN; j++)
			arr[i][j] = 0;

	i = j = 0;
	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\t' || c == '\n'){
			//one word
			if (state == IN){
				arr[i++][j++] = '\0';
				if (j > maxLen)
					maxLen = j;
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


	//maxLen:the max size of one word
	//nw:the number of the word
	//show the *
	for (i = maxLen; i >= 0; i--){
		for ( j = 0; j < nw; j++ ){
			tempMaxLen = maxLen;
			if (arr[j][i] != '\0'){
				putchar('*');
				while (--tempMaxLen)
					putchar(' ');
			}
			while (tempMaxLen--)
				putchar(' ');
		}
		putchar('\n');
	}

	//show the word
	for (i = 0; i < nw; i++){
		for (j = 0; arr[i][j] != '\0'; j++){
			putchar(arr[i][j]);
		}
		while (j++ < maxLen)
			putchar(' ');
	}
}
