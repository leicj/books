#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
void clear(void);

int main(int argc, char **argv)
{
	int	type;
	double	op2;
	char	s[MAXOP];
	double op1;

	while ((type = getop(s)) != EOF){
		switch (type){
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0){
					push(pop() / op2);
				}
				else{
					printf("error:zero divisor\n");
				}
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0){
					push(fmod(pop(), op2));
				}
				else{
					printf("error:zero fmod\n");
				}
				break;
			//打印栈顶元素
			case 'p':
				op2 = pop();
				printf("the head element is:%g\n", op2);
				push(op2);
				break;
			//交换栈顶的前两个元素
			case 's':
				op2 = pop();
				op1 = pop();
				push(op2);
				push(op1);
				break;
			//清空堆栈
			case 'c':
				clear();
				break;
			//pow操作
			case 'P':
				op2 = pop();
				push(pow(pop(), op2));
				break;
			//sin操作
			case 'S':
				push(sin(pop()));
				break;
			//exp操作
			case 'e':
				push(exp(pop()));
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error:unknown command %s\n", s);
				break;
		}
	}

	return 0;
}

#define MAXVAL 100
int		sp = 0;
double	val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL){
		val[sp++] = f;
	}
	else{
		printf("error:stack full, can't push %g\n", f);
	}
}

double pop(void)
{
	if (sp > 0){
		return val[--sp];
	}
	else {
		printf("error:stack empty\n");
		return 0.0;
	}
}

void clear(void)
{
	sp = 0;
}

int	getch(void);
void ungetch(int);

int getop(char s[])
{
	int	i, c;
	int		nextC;

	while ((s[0] = c = getch()) == ' ' || c == '\t'){
		;
	}
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-'){
		return c;
	}
	//判断'-'是减号，而不是负号
	if (!isdigit(nextC = getch()) && c == '-'){
		ungetch(nextC);
		return c;
	}
	ungetch(nextC);

	i = 0;
	if (isdigit(c) || c == '-'){
		while (isdigit(s[++i] = c = getch())){
			;
		}
	}
	if (c == '.'){
		while (isdigit(s[++i] = c = getch())){
			;
		}
	}
	s[i] = '\0';
	if (c != EOF){
		ungetch(c);
	}
	return NUMBER;
}

#define BUFSIZE 100

char	buf[BUFSIZE];
int		bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE){
		printf("ungetch:too many characters\n");
	}
	else{
		buf[bufp++] = c;
	}
}