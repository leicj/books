// 简单的加解密算法

#include <stdio.h>
#include <string.h>

int prepare_key(char *key, char *newkey);
void encrypt(char *data, char const *key);
void decrypt(char *data, char const *key);

int main(void)
{
    char data[] = "ATTACK AT DAWN";
    char key[] = "TRAILBLAZERS";
    char newkey[27] = "";

    if (prepare_key(key, newkey)) {
        printf("key: %s\n", newkey);
        encrypt(data, newkey);
        printf("encrypt data: %s\n", data);
        decrypt(data, newkey);
        printf("decrypt data: %s\n", data);
    } else {
        printf("error key!\n");
    }

    return 0;
}

int prepare_key(char *key, char *newkey)
{
    char *start = newkey;
    while (*key) {
        if (strchr(start, *key) == NULL) {
            *newkey++ = *key;
        }
        key++;
    }
    *newkey = '\0';
    if (newkey - start == 0) {
         return 0;
    }
    for (int ch = 'A'; ch <= 'Z'; ch++) {
        if (strchr(start, ch) == NULL) {
            *newkey++ = ch;
        }
    }
    *newkey = '\0';
    return 1;
}

void encrypt(char *data, char const *key)
{
    while (*data) {
        if (*data >= 'A' && *data <= 'Z') {
            *data = *(key + (*data - 'A'));
        }
        data++;
    }
}


void decrypt(char *data, char const *key)
{
    while (*data) {
        if (*data >= 'A' && *data <= 'Z') {
            *data = strchr(key, *data) - key + 'A';
        }
        data++;
    }
}
