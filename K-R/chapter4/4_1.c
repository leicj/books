#include <stdio.h>

int	strrindex(char *s, char *t);

int main(int argc, char **argv)
{
	char	*s = "hello world hello world";
	printf("%d\n", strrindex(s, "lo w"));
	printf("%d\n", strrindex(s, "wlo w"));

	return 0;
}

int	strrindex(char *s, char *t)
{
	int	i, j, k;
	int	index = -1;

	for (i = 0; s[i] != '\0'; i++){
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++){
			;
		}
		if (k > 0 && t[k] == '\0'){
			index = i;
		}
	}

	return index;
}
