#include <stdio.h>
#define MAXLINE 1024

void expand(char *s1, char *s2);

int main(int argc, char **argv)
{
	char	s1[MAXLINE];
	char	s2[MAXLINE];

	while (fgets(s1, MAXLINE, stdin) != NULL){
		expand(s1, s2);
		printf("%s\n", s2);
	}

	return 0;
}
void expand(char *s1, char *s2)
{
	char	ch;
	while ('\0' != *s1 && '\0' != *(s1 + 1) && '\0' != *(s1 + 2)){
		if (isalnum(*s1) && '-' == *(s1 + 1) && isalnum(*(s1 + 2))){
			if ((isupper(*s1) && isupper(*(s1 + 2))) ||
					islower(*s1) && islower(*(s1 + 2)) ||
					isdigit(*s1) && isdigit(*(s1 + 2))){
				if (*s1 < *(s1 + 2)){
					for (ch = *s1; ch < *(s1 + 2); ch++){
						*s2++ = ch;
					}
				}
				else{
					for (ch = *(s1 + 2); ch > *s1; ch--){
						*s2++ = ch;
					}
				}
				s1 += 2;
			}
			else{
				*s2++ = *s1;
				s1++;
			}
		}
		else{
			*s2++ = *s1;
			s1++;
		}
	}
	if ('\0' != *s1){
		*s2++ = *s1;
	}
	if ('\0' != *(s1 + 1)){
		*s2++ = *(s1 + 1);
	}
	if ('\0' != *(s1 + 2)){
		*s2++ = *(s1 + 2);
	}
	*s2 = '\0';
}
