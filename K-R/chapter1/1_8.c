/*********************
count the space, tab and line number
*******************/
#include <stdio.h>

main()
{
	int		ns, nt, nl, c;
	ns = 0;
	nt = 0;
	nl = 0;
	
	while ((c = getchar()) != EOF){
		if (c == ' ')
			++ns;
		else if (c == '\t')
			++nt;
		else if (c == '\n')
			++nl;
	}

	printf("space:%d\ntab:%d\nlines:%d\n", ns, nt, nl);
}