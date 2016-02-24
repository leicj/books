#include <stdio.h>
#include <ctype.h>

#define SIZE 1024
int getch(void);
void ungetch(int);
int	getfloat(float *pn);

int main(void)
{
	int	i, n;
	float	array[SIZE];

	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++){
		;
	}

	for (i = 0; i < n; i++){
		printf("%f\n", array[i]);
	}

	return 0;
}

#define MAXVAL 1024
int	val[MAXVAL];
int	sp = 0;

//注意这里是前置--
int getch(void)
{
	return sp > 0 ? val[--sp] : getchar();
}

void ungetch(int c)
{
	if (sp > MAXVAL){
		printf("ungetch: too many characters\n");
	}
	else{
		val[sp++] = c;
	}
}

int getint(float *pn)
{
	int	c, sign;
	int	power = 1;

	while (isspace(c = getch())){
		;
	}
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	//跳过'+'或者'-'
	if (c == '+' || c == '-'){
		c = getch();
		//如果符号后面不是数字，则出错
		if (!isdigit(c)){
			ungetch(c);
			return 0;
		}
	}
	//*pn=0会导致输入'+'或者'-'情况下，输出为0
	for (*pn = 0; isdigit(c); c = getch()){
		*pn = 10 * *pn + (c - '0');
	}
	if ('.' == c){
		c = getch();
		for (; isdigit(c); c = getch()){
			*pn = 10 * *pn + (c - '0');
			power *= 10;
		}
	}
	*pn *= sign;
	*pn /= power;
	if (c != EOF){
		ungetch(c);
	}

	return c;
}