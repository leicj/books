#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];
int	myGetline(char *, int);
void swap(char *v[], int i, int j);
//注意：二维数组和字符数组是完全不一样的概念
int readlines(char *lineptr[], int nlines, char line[][MAXLINES]);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main(int argc, char **argv)
{
	int		nlines;
	char	line[200][MAXLINES];

	if ((nlines = readlines(lineptr, MAXLINES, line)) >= 0){
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	}
	else{
		printf("error:input too big to sort\n");
		return 1;
	}
}	


int readlines(char *lineptr[], int maxlines, char line[][MAXLINES])
{
	int	len, nlines;
	int	i = 0;
	nlines = 0;
	while ((len = myGetline(line[i], MAXLINES)) > 0){
		if (nlines >= maxlines){
			return -1;
		}
		else{
			line[i][len - 1] = '\0';
			lineptr[nlines++] = line[i++];
		}
	}

	return nlines;
}

int myGetline(char *s, int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
		s[i] = c;
	}
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0){
		printf("%s\n", *lineptr++);
	}
}

void qsort(char *v[], int left, int right)
{
	int	i, last;

	if (left >= right){
		return;
	}
	swap(v, left, (left + right / 2));
	last = left;
	for (i = left + 1; i <= right; i++){
		if (strcmp(v[i], v[left]) > 0){
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
	char	*temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
