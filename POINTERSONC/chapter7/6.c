#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER 128

void written_amount( unsigned int amount, char **buffer )
{
    char *num[19] = {"ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN",
    "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINTEEN"};
    char *largeNum[8] = {"TWENTY", "THIRTY","FOURTY","FIFTY","SIXTY","SEVENTY","EIGHTY","NINTY"};
    int tempNum = 0;
    int i = 0;
    if ( amount >= 1000 ){
        tempNum = amount / 1000;
        if ( tempNum > 100 ){
            buffer[i++] = num[tempNum / 100 - 1];
            buffer[i++] = " HUNDRED";
            tempNum %= 100;
        }
        if ( tempNum < 20 ){
            buffer[i++] = num[tempNum - 1];
        }
        else{
            buffer[i++] = largeNum[tempNum / 10 - 2];
            buffer[i++] = num[tempNum % 10 - 1];
        }
        buffer[i++] = " THOUSAND ";
    }
    amount %= 1000;
    if ( amount > 100 ){
        buffer[i++] = num[amount / 100 - 1];
        buffer[i++] = " HUNDRED ";
        amount %= 100;
    }
    if ( tempNum < 20 ){
        buffer[i++] = num[tempNum - 1];
    }
    else{
        buffer[i++] = largeNum[tempNum / 10 - 2];
        buffer[i++] = num[tempNum % 10 - 1];
    }
    buffer[i] = '\0';
}

int main(void)
{
    char *arr[MAX_NUMBER];
    int i = 0;
    written_amount(16312, arr);
    for ( i = 0; i < MAX_NUMBER; i++ ){
        if ( arr[i] == '\0' ){
            break;
        }
        printf("%s", arr[i]);
    }

    return 0;
}
