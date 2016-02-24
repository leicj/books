#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

//读取一行数据
int myGetline(char *line, int maxline);
//读取所有输入的数据
int readlines(char *lineptr[], int nlines);
//输出数据
void writelines(char *lineptr[], int nlines);
//进行快速排序
void myQsort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int nReverse, int nocase);
int numcmp(char *, char *);
void swap(void *v[], int i, int j);
//将字符串转换为小写
void upperToLower(char *to, char *from);

int main(int argc, char **argv)
{
	int	nlines;
	int	numeric = 0;	//按照数值大小进行排序
	int reverse = 0;	//按照逆序进行排序
	int	nocase = 0;		//字符串比较时忽略大小写
	int	c;

	while (*++argv != '\0' && (*argv)[0] == '-'){
		while (c = *++*argv){
			switch(c){
				case 'n':
					numeric = 1;
					break;
				case 'r':
					reverse = 1;
					break;
				case 'f':
					nocase = 1;
					break;
				default:
					printf("illegal option %c\n", c);
					return -1;
					break;
			}
		}
	}

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
		myQsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : strcmp), reverse, nocase);
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("input too big to sort\n");
		return 1;
	}
}

int myGetline(char *line, int maxline)
{
	int	i;
	int c;
	for (i = 0; i < maxline && (c = getchar()) != EOF && c != '\n'; i++){
		line[i] = c;
	}
	if ('\n' == c){
		line[i++] = c;
	}
	line[i] = '\0';
	return i;
}

int readlines(char *lineptr[], int maxline)
{
	int	len;
	int nlines;
	char	*p, line[MAXLINES];
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
void writelines(char *lineptr[], int nlines)
{
	int	i;
	while (nlines--){
		printf("%s\n", *lineptr++);
	}
}
void myQsort(void *v[], int left, int right, int (*comp)(void *, void *), int nReverse, int nocase)
{
	int	i, last;
	char	tempLeft[MAXLINES];
	char	tempRight[MAXLINES];
	if (left >= right){
		return;
	}
	swap(v, left, (left + right / 2));
	last = left;
	for (i = left + 1; i <= right; i++){
		if (nocase){
			upperToLower(tempLeft, v[i]);
			upperToLower(tempRight, v[left]);
			if ((nReverse && (*comp)(tempLeft, tempRight) > 0) ||
					(!nReverse && (*comp)(tempLeft, tempRight) < 0)){
				swap(v, ++last, i);
			}
		}
		else {
			if ((nReverse && (*comp)(v[i], v[left]) > 0) ||
					(!nReverse && (*comp)(v[i], v[left]) < 0)){
				swap(v, ++last, i);
			}
		}
	}
	swap(v, left, last);
	myQsort(v, left, last - 1, comp, nReverse, nocase);
	myQsort(v, last + 1, right, comp, nReverse, nocase);
}

int numcmp(char *s1, char *s2)
{
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}
void swap(void *v[], int i, int j)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
void upperToLower(char *to, char *from)
{
	while ('\0' != *from){
		if (isupper(*from)){
			*to = tolower(*from);
		}
		else{
			*to =  *from;
		}
		to++;
		from++;
	}
}
