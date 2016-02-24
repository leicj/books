#include <stdio.h>

#define IN 1		//in the word
#define OUT 0		//out the word
main()
{
	int		c;
	int		state;

	state = OUT;

	while ((c = getchar()) != EOF){
		//not a word
		if (c == ' ' || c == '\t' || c == '\n'){
			if (state == IN)
				putchar('\n');
			state = OUT;
		}
		//the first character of the word
		else if (state == OUT){
			putchar(c);
			state = IN;
		}
		//the remaining character after the first character of the word
		else if (state == IN){
			putchar(c);
		}
	}
}