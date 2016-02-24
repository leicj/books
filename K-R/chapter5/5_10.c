#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

//这里为什么不能用*号？？？？？
int main(int argc, char **argv)
{
	float	line[MAXLINE];
	int		sp = 0;
	char	*temp;
	while (*++argv != '\0'){
		if (!strcmp("+", *argv)){
			line[sp - 2] += line[sp - 1];
			sp--;
		}
		else if (!strcmp("-", *argv)){
			line[sp - 2] -= line[sp - 1];
			sp--;
		}
		else if (!strcmp("*", *argv)){
			line[sp - 2] *= line[sp - 1];
			sp--;
		}
		else if (!strcmp("/", *argv)){
			if (0.0 != line[sp]){
				line[sp - 2] /= line[sp - 1];
			}
			else{
				printf("can not divisor zero\n");
				return -1;
			}
		}
		else{
			temp = *argv;
			while (**argv != '\0' && (isdigit(**argv) || '.' == **argv)){
				++*argv;
			}
			if (**argv == '\0'){
				line[sp++] = atof(temp);
			}
			else{
				printf("not a float number\n");
			}
		}
	}

	printf("%f\n", line[0]);

	return 0;
}
