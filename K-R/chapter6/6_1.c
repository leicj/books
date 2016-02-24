#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct key{
	char	*word;
	int		count;
} keytab[] = {{"auto", 0}, {"break", 0}, {"case", 0}, {"char", 0}, {"const", 0}, 
{"continue", 0}, {"default", 0}, {"unsigned", 0}, {"void", 0}, {"volatile", 0}, {"while", 0}};

int getword(char *, int);
int binsearch(char *, struct key *, int);

int main(void)
{
	int	n;
	char	word[MAXWORD];
	int	NKEYS = sizeof(keytab) / sizeof(*keytab);

	while (getword(word, MAXWORD) != EOF){
		if (isalpha(word[0]) || '_' == word[0]){
			if ((n = binsearch(word, keytab, NKEYS)) >= 0){
				keytab[n].count++;
			}
		}
	}

	for (n = 0; n < NKEYS; n++){
		if (keytab[n].count > 0){
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
		}
	}

	return 0;
}

int binsearch(char *word, struct key *tab, int n)
{
	int		cond;
	int		low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high){
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0){
			high = mid - 1;
		}
		else if (cond > 0){
			low = mid + 1;
		}
		else {
			return mid;
		}
	}

	return -1;
}

int getch(void);
void ungetch(int c);
#define MAXLINES 1000
int	val[MAXLINES];
int sp = 0;

void comment();
int getword(char *word, int lim)
{
	int		c;
	char 	*w = word;

	while (isspace(c = getch())){
		;
	}
	if (c != EOF && '/' != c){
		*w++ = c;
	}
	if (!isalpha(c) && '_' != c && '/' != c){
		*w = '\0';
		return c;
	}
	if ((isalpha(c) || '_' == c) && '/' != c){
		for (; --lim > 0; w++){
			if (!isalnum(*w = getch()) && '_' != *w){
				ungetch(*w);
				break;
			}
		}
	}
	else if ('/' == c){
		if ('*' == (c = getch())){
			comment();
		}
		else{
			ungetch(c);
		}
	}
	*w = '\0';
	return word[0];
}

int getch(void)
{
	return (sp > 0) ? val[--sp] : getchar();
}

void ungetch(int c)
{
	if (sp >= MAXLINES){
		printf("ungetch:too many characters\n");
	}
	else {
		val[sp++] = c;
	}
}

void comment()
{
	int		c;
	while ((c = getch()) != EOF){
		if ('*' == c){
			if ('/' == (c = getch())){
				break;
			}
		}
	}
}