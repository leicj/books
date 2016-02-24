#include <stdio.h>

int		htoi(char *s);

int main(void)
{
	printf("%d\n", htoi( "0x1b2" ) );
	printf("%d\n", htoi( "0xff" ) );
	printf("%d\n", htoi( "0x1abc" ) );
}

int		htoi(char *s)
{
	int		num = 0;
	int		tempNum = 0;

	if ( '0' == *s && ( 'x' == *(s + 1) || 'X' == *(s + 1))){
		s += 2;
	}

	while ('\0' != *s){
		if (*s >= 'a' && *s <= 'f'){
			tempNum = *s - 'a' + 10;
		}
		else if (*s >= 'A' && *s <= 'F'){
			tempNum = *s - 'A' + 10;
		}
		else{
			tempNum = *s - '0';
		}

		num = num * 16 + tempNum;
		s++;
	}

	return num;
}