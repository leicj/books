/*******************************
signed, unsigned char, short, int, long min/max value 
********************************/
#include <stdio.h>
#include <limits.h>

int main(void)
{
	unsigned char	uch;
	unsigned short	ushort;
	unsigned int	uint;
	unsigned long	ulong;
	signed	  char	sch;
	signed    short	sshort;
	signed    int	sint;
	signed	  long	slong;

	printf("char min:%d\n", CHAR_MIN);
	printf("char max:%d\n", CHAR_MAX);
	printf("short min:%d\n", SHRT_MIN);
	printf("short max:%d\n", SHRT_MAX);
	printf("int min:%d\n", INT_MIN);
	printf("int max:%d\n", INT_MAX);
	printf("long min:%d\n", LONG_MIN);
	printf("long max:%d\n", LONG_MAX);
	printf("unsigned char max:%d\n", UCHAR_MAX);
	printf("unsigned short max:%d\n", USHRT_MAX);
	printf("unsigned int max:%lu\n", UINT_MAX);
	printf("unsigned long max:%lu\n", ULONG_MAX);

	printf("\n####################\n");

	sch = 0;
	while (sch >= 0){
		sch++;
	}
	printf("char min:%d\n", sch);
	sch -= 1;
	printf("char max:%d\n", sch);

	sshort = 0;
	while (sshort >= 0){
		sshort++;
	}
	printf("short min:%d\n", sshort);
	sshort -= 1;
	printf("short max:%d\n", sshort);

	sint = 0;
	while (sint >= 0){
		sint++;
	}
	printf("int min:%d\n", sint);
	sint -= 1;
	printf("int max:%d\n", sint);

	slong = 0;
	while (slong >= 0){
		slong++;
	}
	printf("long min:%d\n", slong);
	slong -= 1;
	printf("long max:%d\n", slong);

	uch = -1;
	ushort = -1;
	uint = -1;
	ulong = -1;
	printf("unsigned char max:%d\n", uch);
	printf("unsigned short max:%d\n", ushort);
	printf("unsigned int max:%lu\n", uint);
	printf("unsigned long max:%lu\n", ulong);

	return 0;
}