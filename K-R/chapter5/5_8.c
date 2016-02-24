#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day)
{
	int i, leap;

	if (month < 1 || month > 12){
		printf("month must be in 1~12\n");
		return 0;
	}
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (day < 1 || day > daytab[leap][month]){
		printf("day must be in 0~%d\n", daytab[leap][month]);
		return 0;
	}
	for (i = 1; i < month; i++){
		day += daytab[leap][i];
	}
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int	i, leap;
	int	totalDay = 0;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	
	for (i = 1; i <= 12; i++){
		totalDay += daytab[leap][i];
	}
	if (yearday < 1 || yearday > totalDay){
		printf("day must be in 1~%d\n", totalDay);
		return;
	}
	
	for (i = 1; yearday > daytab[leap][i]; i++){
		yearday -= daytab[leap][i];
	}
	*pmonth = i;
	*pday = yearday;
}

int main(int argc, char **argv)
{
	int	month, day;
	printf("%d\n", day_of_year(2014, 10, 31));
	printf("%d\n", day_of_year(2000, 2, 29));
	printf("%d\n", day_of_year(2014, 2, 29));

	month_day(2014, 89, &month, &day);
	printf("%d-%d\n", month, day);

	return 0;
}
