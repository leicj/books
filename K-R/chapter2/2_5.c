#include <stdio.h>

int any(char *s1, char *s2)
{
	char		*temp = s1;			//用于存储每次修改的值
	char		*newstr = temp;		//用于初始化修改后的值

	while ('\0' != *s2){
		s1 = newstr;
		while ('\0' != *s1){
			if (*s1 == *s2){
				return s1 - temp;
			}
			s1++;
		}
		s2++;
	}
}

int main(void)
{
	char s1[] = "hello world i love this world";
	char s2[] = "lsad";
	printf("%d\n", any(s1, s2) );

	return 0;
}