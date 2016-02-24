#include <stdio.h>

void squeeze(char *s1, char *s2)
{
	char		*temp = s1;			//用于存储每次修改的值
	char		*newstr = temp;		//用于初始化修改后的值

	while ('\0' != *s2){
		s1 = newstr;
		temp = newstr;
		while ('\0' != *s1){
			if (*s1 != *s2){
				*temp++ = *s1;
			}
			s1++;
		}
		*temp = '\0';
		s2++;
	}
}

int main(void)
{
	char s1[] = "hello world i love this world";
	char s2[] = "els";
	squeeze( s1, s2 );
	printf("%s\n", s1 );

	return 0;
}