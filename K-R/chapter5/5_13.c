#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 10
#define MAXLINES 1000

int readlines(char *lineptr[], int maxline);
int	myGetline(char *line, int maxline);
void writelines(char *lineptr[], int nline, int tailLine);

int main(int argc, char **argv)
{
	char	*lineptr[MAXLINES];
	int		len = 0;
	int		n = 0;
	char	*temp;
	while (*++argv != '\0' && (*argv)[0] == '-'){
		temp = ++argv[0];
		while (**argv != '\0' && (isdigit(**argv))){
			++*argv;
		}
		if (**argv == '\0'){
			n = atof(temp);
		}
		else{
			n = MAXLEN;
		}
	}

	if ((len = readlines(lineptr, MAXLINES)) >= 0){
		writelines(lineptr, len, n);	
	}

	return 0;
}

int	myGetline(char *line, int maxline)
{
	int	i = 0;
	int	c;

	for (i = 0; i < maxline && (c = getchar()) != EOF && c != '\n'; i++){
		line[i] = c;
	}
	if (c == '\n'){
		line[i++] = c;
	}
	line[i] = '\0';

	return i;
}
int readlines(char *lineptr[], int maxline)
{
	int	len, nlines;
	char *p, line[MAXLINES];
	
	nlines = 0;
	while ((len = myGetline(line, MAXLINES)) > 0){
		if (nlines >= maxline || (p = malloc(sizeof(char) * len)) == NULL){
			return -1;
		}
		else{
			line[len - 1] = '\0';
			strncpy(p, line, len);
			lineptr[nlines++] = p;
		}
	}

	return nlines;
}

void writelines(char *lineptr[], int nline, int tailLine)
{
	int	i = 0;
	int	index = 0;

	index = nline - tailLine < 0 ? 0 : nline - tailLine;
	for (i = index; i < nline; i++){
		printf("%s\n", lineptr[i]);
	}
}
