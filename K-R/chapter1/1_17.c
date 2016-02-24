/********************
  print the line, which size largest MAXLIMIT
  ******************/
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 5	
#define MAXLIMIT 10
//get one line
int myGetline(char *line, int max);
//copy the line
void myCopy(char *to, char *from);

int main(int argc, char **argv)
{
	char	*line;
	char	*lineArr[1024];
	int		len;
	int		max;
	int		i = 0;
	int		lineNum = 0;

	line = malloc(sizeof(char) * MAXLINE);

	max = 0;
	while ((len = myGetline(line, max == 0 ? MAXLINE : max)) > 0 && i < 1024 - 1){
		if (len > max){
			max = len;
		}
		if (len > MAXLIMIT){
			lineArr[i] = realloc(lineArr[i], max);
			myCopy(lineArr[i], line);
			i++;
		}
	}

	lineNum = i;
	for (i = 0; i < lineNum; i++){
		printf("%s\n", lineArr[i]);
	}

	for (i = 0; i < lineNum; i++){
		free(lineArr[i]);
	}
	free(line);

	return 0;
}
int myGetline(char *line, int max)
{
	char	*oldLine = line;
	char	ch;
	int		nw;
	nw = 0;
	while ((ch = getchar()) != EOF && ch != '\n'){
		*oldLine++ = ch;
		nw++;
		if (nw >= max){
			line = realloc(line, sizeof(char) * max * 2);
			max *= 2;
			oldLine = line + nw;
		}
	}

	*oldLine = '\0';
	return nw;
}
void myCopy(char *to, char *from)
{
	while (*to++ = *from++){
		;
	}
}

