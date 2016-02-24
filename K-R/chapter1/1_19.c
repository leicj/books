/********************
  reverse line
  ******************/
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 5	

//get one line
int myGetline(char *line, int max);
//copy the line
void myCopy(char *to, char *from);
//reverse the line
void reverse(char *line);

int main(int argc, char **argv)
{
	char	*line;
	int		len;
	int		max;

	line = malloc(sizeof(char) * MAXLINE);

	max = 0;
	while ((len = myGetline(line, max == 0 ? MAXLINE : max)) > 0){
		reverse(line);
		printf("%s\n", line);
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

void reverse(char *line)
{
	char	*begin = line;
	char	temp;
	while (*line){
		line++;
	}
	line--;
	while (begin < line){
		temp = *begin;
		*begin++ = *line;
		*line-- = temp;
	}
}
