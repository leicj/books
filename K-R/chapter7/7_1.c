/****************************
通过命令行来选择输出小写还是大写字符串
******************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv)
{
	int		isLower = 0;
	int		isUpper = 0;
	int		c;

	if (argc != 2){
		printf("argument should be 2\n");
		return 1;
	}

	while (--argc && (*++argv)[0] == '-'){
		switch (c = *(++*argv)){
			case 'l':
				isLower = 1;
				break;
			case 'u':
				isUpper = 1;
				break;
			default:
				printf("unknown command\n");
				break;
		}
	}

	while ((c = getchar()) != EOF){
		if (isLower){
			putchar(tolower(c));
		}
		else if (isUpper){
			putchar(toupper(c));
		}
		else{
			putchar(c);
		}
	}

	return 0;
}