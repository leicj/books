/************************
1. 以合理的方式打印任何输入，并根据用户习惯以八进制或十六进制
打印非图形字符(二进制数据)，并截断长文本行
2. 参考于：http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_7:Exercise_2
**************************/

#include <stdio.h>

#define OCTAL 8
#define HEXADECIMAL 16

int can_print(int ch)
{
	char	*printable = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 !\"#%&'()*+,-./:;<=>?[\\]^_{|}~\t\f\v\r\n";
	
	char	*s;
	int		found = 0;
	
	for (s = printable; !found && *s; s++){
		if (*s == ch){
			found = 1;
		}
	}
	
	return found;
}

int main(int argc, char **argv)
{
	int		isOct = 0;
	int		isHex = 0;
	int		isDec = 0;
	int		ch;
	int		split = 80;
	int		textrun = 0;
	int		binaryrun = 0;
	int		width = 0;
	char	*format;

	while (--argc && (*++argv)[0] == '-'){
		switch (c = *(++*argv)){
			case 'o':
			case 'O':
				isOct = 1;
				format = "%02X ";
				width = 4;
				break;
			case 'h':
			case 'H':
				isHex = 1;
				format = "%3o ";
				width = 4;
				break;
			default:
				isDec = 1;
				break;
		}
	}
	
	while ((ch = getchar()) != EOF){
		if (can_print(ch)){
			if (binaryrun > 0){
				putchar('\n');
				binaryrun = 0;
				textrun = 0;
			}
			putchar(ch);
			++textrun;
			if (ch == '\n'){
				textrun = 0;
			}
			if (textrun == split){
				putchar('\n');
				textrun = 0;
			}
		}
		else {
			if (textrun > 0 || binaryrun + width >= split){
				printf("\nbinary stream: ");
				textrun = 0;
				binaryrun = 15;
			}
			printf(format, ch);
			binaryrun += width;
		}
	}
	putchar('\n');
	
	return 0;
}