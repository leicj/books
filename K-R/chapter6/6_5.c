#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist {
	struct 	nlist *next;
	char	*name;
	char	*defn;
};
#define HASHSIZE 5
static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
char *strdup(char *);
void undef(char *);
void print(void);

int main(void)
{
	install("A", "1");
	install("Y", "1");
	install("Z", "1");
	install("IN", "1");
	install("OUT", "0");
	install("MAXLINE", "1000");
	install("SIZZ", "100");
	install("SIZA", "12345");

	print();
	undef("SIZZ");
	print();

	return 0;
}

void undef( char *s )
{
	int h;
	struct nlist *prev, *np;

	prev = NULL;
	h = hash( s );
	for ( np = hashtab[ h ]; np != NULL; np = np->next ){
		if ( strcmp( s, np->name ) == 0 ){
			break;
		}
		prev = np;
	}
	if ( np != NULL ){
		if ( prev == NULL ){
			hashtab[ h ] = np->next;
		}
		else{
			prev->next = np->next;
		}
		free( ( void * )np->name );
		free( ( void * )np->defn );
		free( ( void * )np );
	}
}

void print(void)
{
	int		i = 0;
	struct nlist  *np;
	for (i = 0; i < HASHSIZE; i++){
		np = hashtab[i];
		for (; np != NULL; np = np->next){
			printf("%s<--->%s\n", np->name, np->defn);
		}
	}
	printf("#################\n");
}

unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++){
		hashval = *s + 25 * hashval;
	}

	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next){
		if (strcmp(s, np->name) == 0){
			return np;
		}
	}

	return NULL;
}

struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL){
		np = (struct nlist *)malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL){
			return NULL;
		}
		hashval = hash(name);
		//插入链表头部
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else {
		free((void *)np->defn);
	}
	if ((np->defn = strdup(defn)) == NULL){
		return NULL;
	}

	return np;
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