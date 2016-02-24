#include <stdio.h>

void strcat(char *s, char *t)
{
	while (*s != '\0'){
		s++;
	}
	while (*s++ = *t++){
		;
	}
}

int main(void)
{
	char	s[1024] = "hello ";
	char	*t = "world";
	
	strcat(s, t);
	printf("%s\n", s);
	
	return 0;
}