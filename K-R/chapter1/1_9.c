/***********************
put multi-space to one space, and show the input centense
*********************/
#include <stdio.h>

main()
{
	int		c;
	int		isSpace;	//is the space

	isSpace = 0;
	while ((c = getchar()) != EOF){
		if (c == ' ' && !isSpace){
			isSpace = 1;
		}
		else if (c == ' ' && isSpace){
			continue;
		} 
		else{
			isSpace = 0;
		}
		putchar(c);
	}
}