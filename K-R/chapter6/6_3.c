#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define LINENUM 100

struct tnode {
	char	*word;
	int		count;
	struct 	tnode *left;
	struct 	tnode *right;
	int		sp;
	int		line[LINENUM];
};
struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int, int *);

int main(void)
{
	struct 	tnode *root;
	char	word[MAXWORD];
	int			lineNum = 1;

	root = NULL;
	while (getword(word, MAXWORD, &lineNum) != EOF){
		if (isalpha(word[0]) || '_' == word[0]){
			root = addtree(root, word, lineNum);
		}
	}
	treeprint(root);

	return 0;
}

struct tnode *talloc(void);
char *strdup(char *);
struct tnode *addtree(struct tnode *p, char *w, int lineNum)
{
	int cond;
	if (NULL == p){
		p = talloc();
		p->word = strdup(w);
		p->count = 1;
		p->sp = 0;
		(p->line)[p->sp] = lineNum;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0){
		p->count++;
		p->sp++;
		(p->line)[p->sp] = lineNum;
	} else if (cond < 0){
		p->left = addtree(p->left, w, lineNum);
	} else{
		p->right = addtree(p->right, w, lineNum);
	}

	return p;
}

void treeprint(struct tnode *p)
{
	int		i = 0;
	if (p != NULL){
		treeprint(p->left);
		printf("%4d %s occures in lines:", p->count, p->word);
		for (i = 0; i <= p->sp; i++){
			printf("%d ", (p->line)[i]);
		}
		printf("\n");
		treeprint(p->right);
	}
}

struct tnode *talloc(void)
{
	return (struct tnode *)malloc(sizeof(struct tnode));
}

char *strdup(char *s)
{
	char	*p;
	p = (char *)malloc(strlen(s) + 1);
	if (p != NULL){
		strcpy(p, s);
	}

	return p;
}

int getch(void);
void ungetch(int c);
#define MAXLINES 1000
int	val[MAXLINES];
int sp = 0;

void comment();
int getword(char *word, int lim, int *lineNum)
{
	int		c;
	char 	*w = word;

	while (isspace(c = getch())){
		//出现换行符
		if ('\n' == c){
			(*lineNum)++;
		}
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