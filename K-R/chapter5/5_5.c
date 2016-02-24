#include <stdio.h>

void strncpy(char *s, char *t, int n)
{
	//这里括号是必须的，注意运算符的优先级
	while ((*s++ = *t++) && n-- > 0){
		;
	}
	*s = '\0';
}

void strncat(char *s, char *t, int n)
{
	while (*s != '\0'){
		s++;
	}
	while ((*s++ = *t++) && n-- > 0){
		;
	}
	*s = '\0';
}

int strncmp(char *s, char *t, int n)
{
	for (; (*s == *t) && n-- > 0; s++, t++){
		if ('\0' == *s){
			return 0;
		}
	}

	return *s - *t;
}

int main(void)
{
	char	s[1024] = "hello world";
	char	*t = "i love this world and i love c too";

	strncpy(s, t, 6);
	printf("%s\n", s);
	strncpy(s, t, 15);
	printf("%s\n", s);

	strncat(s, t, 6);
	printf("%s\n", s);
	strncat(s, t, 100);
	printf("%s\n", s);

	printf("%d\n", strncmp(s, "i love www", 5));
	printf("%d\n", strncmp(s, "i love www", 12));

	return 0;
}