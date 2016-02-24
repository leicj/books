#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode {
	char	*word;
	int		count;
	struct 	tnode *left;
	struct 	tnode *right;
};

typedef struct WORD{
	char	*word;
	int		count;
}Word;

struct tnode *addtree(struct tnode *, char *);
Word * treeToArr(struct tnode *, Word *allWord);
int getword(char *, int);


int main(void)
{
	struct 	tnode *root;
	char	word[MAXWORD];
	Word	allWord[MAXWORD];
	Word	*p = allWord;
	int			len = 0;				//单词的总数
	int			i = 0;
	int			j = 0;

	root = NULL;
	while (getword(word, MAXWORD) != EOF){
		if (isalpha(word[0]) || '_' == word[0]){
			root = addtree(root, word);
		}
	}
	p = treeToArr(root, allWord);
	len = p - allWord;

	for (i = 0; i < len-1; i++){
		for (j = i + 1; j < len; j++){
			if (allWord[i].count < allWord[j].count){
				Word	temp = allWord[i];
				allWord[i] = allWord[j];
				allWord[j] = temp;
			}
		}
	}

	for (i = 0; i < len; i++){
		printf("%s:%d\n", allWord[i].word, allWord[i].count);
	}
	printf("\n");

	return 0;
}

struct tnode *talloc(void);
char *strdup(char *);
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;
	if (NULL == p){
		p = talloc();
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0){
		p->count++;
	} else if (cond < 0){
		p->left = addtree(p->left, w);
	} else{
		p->right = addtree(p->right, w);
	}

	return p;
}

Word *treeToArr(struct tnode *p, Word *allWord)
{
	if (p != NULL){
		allWord = treeToArr(p->left, allWord);
		allWord->count = p->count;
		allWord->word = p->word;
		allWord++;
		allWord = treeToArr(p->right, allWord);
	}
	return allWord;
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