#include <stdio.h>

int strend(char *s, char *t)
{
	int		lenT = strlen(t);
	int		lenS = strlen(s);
	
	for (; *(s + lenS - lenT) == *t; s++, t++){
		if ('\0' == *t){
			return 1;
		}
	}
	
	return 0;
}

int main(void)
{
	char	*s = "hello world";
	
	printf("%d\n", strend(s, "world"));
	printf("%d\n", strend(s, "wrld"));
	
	return 0;
}