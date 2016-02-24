#include <stdio.h>

void escape(char *s, char *t)
{
	while ('\0' != *t){
		switch(*t){
			case '\n':
				*s++ = '\\';
				*s++ = 'n';
				break;
			case '\t':
				*s++ = '\\';
				*s++ = 't';
				break;
			default:
				*s++ = *t;
		}
		t++;
	}
	*s = '\0';
}

void difEscape(char *s, char *t)
{
	while ('\0' != *t){
		if ('\\' == *t && 'n' == *(t + 1)){
			*s++ = '\n';
			t += 2;
		}
		else if ('\\' == *t && 't' == *(t + 1)){
			*s++ = '\t';
			t += 2;
		}
		else{
			*s++ = *t++;
		}
	}
	*s = '\0';
}

int main(void)
{
	char s[128];
	char t[] = "hello\nworld\ti love this world\n";
	escape( s, t );
	printf("%s\n", t);
	printf("%s\n", s );
	difEscape(s, s);
	printf("%s\n", s);

	return 0;
}