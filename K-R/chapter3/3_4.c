#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void myItoa(int n, char s[]);
void reverse(char s[]);

int main(int argc, char *argv)
{
	char	s[128];
	myItoa(INT_MAX, s);
	printf("%s\n", s);
	myItoa(INT_MIN, s);
	printf("%s\n", s);

	return 0;
}

void myItoa(int n, char s[])
{
	int	i, sign;
	int	isMIN = 0;
	i = 0;
	
	if (n == -n){
		isMIN = 1;
		n += 1;
	}
	if ((sign = n) < 0){
		n = -n;
	}
	if (isMIN){
		s[i++] = n % 10 + 1 + '0';
		n /= 10;
	}
	do{
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0){
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}
void reverse(char s[])
{
	int	i, j, ch;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
		ch = s[i];
		s[i] = s[j];
		s[j] = ch;
	}
}
