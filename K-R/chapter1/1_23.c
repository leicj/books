/***********************
删除注释
************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAXSIZE 128
#define LINENUM 20
 
int isDoubleSlash;      //出现注释符'//'
int isSlashStar;        //出现注释符/**/
 
void dealLine( char *line, char **mulLine, int index )
{
    int len = strlen( line );
    char *newLine = malloc( len * sizeof( char ));
    char *temp = newLine;
    while ( '\n' != *line ){        //备注:getline是以换行符/n结束,而不是以\0结束
        if ( '/' == *line && '/' == *( line + 1 ) ){
            isDoubleSlash = 1;
        }
        else if ( '/' == *line && '*' == *( line + 1 ) ){
            isSlashStar = 1;
        }
        if ( isDoubleSlash ){   //出现'//',直接忽略后面的注释字符串
            isDoubleSlash = 0;
            *line = '\0';
            break;
        }
        if ( isSlashStar && '*' == *line && '/' == *( line + 1 ) && '/' != *( line - 1 ) ){ //防止出现/*/的情况
            isSlashStar = 0;
            line += 2;
            continue;
        }
        if ( !isSlashStar ){
            *temp = *line;
            temp++;
        }
        line++;
    }
    *temp = '\0';
    mulLine[ index ] = newLine;
}
 
int main(void)
{
    int     ch;
    char    line[ MAXSIZE ];
    char    *mulLine[ LINENUM ];
    int     index = 0;
    int     i = 0;
    int     j = 0;
 
    for ( i = 0; i < MAXSIZE; i++ ){
        line[ i ] = '\0';
    }
    for ( i = 0; i < LINENUM; i++ ){
        mulLine[ i ] = "";
    }
 
    while ( NULL != fgets( line, MAXSIZE, stdin ) ){
        dealLine( line, mulLine, index );
        index++;
    }
 
    printf("\nthe text is:\n");
    for ( i = 0; i < LINENUM; i++ ){
        if ( '\0' != mulLine[ i ][ 0 ] ){       //不要进行"" != mulLine[ i ]的判断
            printf("%s\n", mulLine[ i ] );
        }
    }
 
    return 0;
}
