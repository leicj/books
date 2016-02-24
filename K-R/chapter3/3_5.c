#include <stdio.h>

void itob(int n, char s[], int b);
void reverse(char s[]);
int main(int argc, char **argv)
{
	char	s[128];
	itob(123, s, 16);
	printf("%s\n", s);
	itob(123, s, 7);
	printf("%s\n", s);

	return 0;
}
void itob(int n, char s[], int b)
{
	int	i, sign, isMIN;

	isMIN = 0;
	i = 0;
	if (n == -n){
		isMIN = 1;
		n += 1;
	}
	if ((sign = n) < 0){
		n = -n;
	}
	if (isMIN){
		s[i++] = n % b + 1 + '0';
		n /= b;
	}

	do{
		if (n % b > 10){
			s[i++] = n % b - 10 + 'a';
		}
		else{
			s[i++] = n % b + '0';
		}
	} while ((n /= b) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
void reverse(char s[])
{
	char	ch;
	char *temp = s;
	while ('\0' != *temp){
		temp++;
	}
	temp--;
	while (s < temp){
		ch = *s;
		*s++ = *temp;
		*temp-- = ch;
	}
}
