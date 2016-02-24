/****************************
change Celsius temperature to Fahrenheit
****************************/
#include <stdio.h>

main()
{
	float	fahr, celsius;
	int	lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;
	while (celsius <= upper){
		fahr = 9 * celsius / 5 + 32;
		printf("%3.0f\t%6.1f\n", celsius, fahr);
		celsius += step;
	}
}