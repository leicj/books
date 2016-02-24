#include <stdio.h>
#include <math.h>
#include <ctype.h>

double atof(char s[])
{
	double val, power, exVal;
	int	i, sign, exSign;

	for (i = 0; isspace(s[i]); i++){
		;
	}
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-'){
		i++;
	}
	for (val = 0.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.'){
		i++;
	}
	for (power = 1.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if (s[i] == 'e'){
		i++;
	}
	if (s[i] == '-'){
		i++;
		exSign = -1;
	} else if (s[i] == '+'){
		i++;
		exSign = 1;
	}
	for (exVal = 0; isdigit(s[i]); i++){
		exVal = 10 * exVal + (s[i] - '0');
	}

	return sign * val / power * pow(10.0, exSign * exVal);
}

int main(int argc, char **argv)
{
	printf("%g\n", atof("1234.567e-11"));

	return 0;
}
