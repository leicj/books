// 多项式的链表实现形式

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct POLYNOMIAL {
    struct POLYNOMIAL *next;
    int cof;
    int exp;
} Pol;

// 多项式相加
Pol *add(Pol *pol1, Pol *pol2);
// 多项式相乘
Pol *mul(Pol *pol1, Pol *pol2);
// 插入多项式
void insert(Pol *root, Pol *pol);
// 打印多项式
void print(Pol *pol);

int main(void)
{
    Pol pol1, pol2, pol3, pol4, pol5, pol6;
    Pol *poladd = (Pol *)malloc(sizeof(Pol));
    Pol *polmul = (Pol *)malloc(sizeof(Pol));
    pol1.cof = 2;
    pol1.exp = 2;
    pol2.cof = 1;
    pol2.exp = 1;
    pol3.cof = -1;
    pol3.exp = 0;
    pol1.next = &pol2;
    pol2.next = &pol3;
    pol3.next = NULL;

    pol4.cof = 3;
    pol4.exp = 3;
    pol5.cof = 2;
    pol5.exp = 1;
    pol6.cof = -3;
    pol6.exp = 0;
    pol4.next = &pol5;
    pol5.next = &pol6;
    pol6.next = NULL;

    poladd = add(&pol1, &pol4);
    polmul = mul(&pol1, &pol4);

    print(poladd);
    print(polmul);

    return 0;
}


Pol *add(Pol *pol1, Pol *pol2)
{
    Pol *poladd = NULL;
    Pol *prevpol = poladd;

    while (pol1 && pol2) {
        Pol *temppol = (Pol *)malloc(sizeof(Pol));
        if (pol1->exp > pol2->exp) {
            temppol->exp = pol1->exp;
            temppol->cof = pol1->cof;
            temppol->next = NULL;
            pol1 = pol1->next;
        } else if (pol1->exp < pol2->exp) {
            temppol->exp = pol2->exp;
            temppol->cof = pol2->cof;
            temppol->next = NULL;
            pol2 = pol2->next;
        } else {
            temppol->exp = pol1->exp;
            temppol->cof = pol1->cof + pol2->cof;
            temppol->next = NULL;
            pol1 = pol1->next;
            pol2 = pol2->next;
        }
        if (NULL == poladd) {
            poladd = temppol;
            prevpol = poladd;
        } else {
            prevpol->next = temppol;
            prevpol = temppol;
        }
    }

    while (pol1) {
        Pol *temppol = (Pol *)malloc(sizeof(Pol));
        temppol->exp = pol1->exp;
        temppol->cof = pol1->cof;
        temppol->next = NULL;
        prevpol->next = temppol;
        prevpol = temppol;
        pol1 = pol1->next;
    }
    while (pol2) {
        Pol *temppol = (Pol *)malloc(sizeof(Pol));
        temppol->exp = pol2->exp;
        temppol->cof = pol2->cof;
        temppol->next = NULL;
        prevpol->next = temppol;
        prevpol = temppol;
        pol2 = pol2->next;
    }

    return poladd;
}

void print(Pol *pol)
{
    while (pol) {
        printf("%d * x ^ %d + ", pol->cof, pol->exp);
        pol = pol->next;
    }
    printf("\n");
}


Pol *mul(Pol *pol1, Pol *pol2)
{
    Pol *polmul = (Pol *)malloc(sizeof(Pol));
    polmul->cof = INT_MIN;
    polmul->exp = INT_MIN;
    polmul->next = NULL;
    Pol *pol2head = pol2;

    while (pol1) {
        pol2 = pol2head;
        while (pol2) {
            Pol *temppol = (Pol *)malloc(sizeof(Pol));
            temppol->cof = pol1->cof * pol2->cof;
            temppol->exp = pol1->exp + pol2->exp;
            temppol->next = NULL;
            insert(polmul, temppol);
            pol2 = pol2->next;
        }
        pol1 = pol1->next;
    }

    return polmul->next;
}


void insert(Pol *root, Pol *pol)
{
    Pol *prevnode = root;
    root = root->next;

    if (NULL == root) {
        prevnode->next = pol;
        return;
    }
    while (root && root->exp > pol->exp) {
        prevnode = root;
        root = root->next;
    }

    if (root && root->exp == pol->exp) {
        root->cof += pol->cof;
    } else if (root && root->exp < pol->exp) {
        prevnode->next = pol;
        pol->next = root;
    } else {
        prevnode->next = pol;
    }
}
