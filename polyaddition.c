#include <stdio.h>

struct poly {
    int coeff;
    int expo;
};

int readPoly(struct poly []);
void displayPoly(struct poly [], int terms);
int addPoly(struct poly [], struct poly [], int, int, struct poly []);

int main() {
    struct poly pl[10], p2[10], p3[10];
    int t1, t2, terms;

    terms = readPoly(pl);
    displayPoly(pl, terms);

    t1 = readPoly(p2);
    displayPoly(p2, t1);

    t2 = addPoly(pl, p2, terms, t1, p3);
    displayPoly(p3, t2);

    return 0;
}

int readPoly(struct poly p[10]) {
    int terms, i;

    printf("\nEnter the total number of terms in the polynomial:");
    scanf("%d", &terms);

    printf("\nEnter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");

    for (i = 0; i < terms; i++) {
        printf("Enter the Coefficient(%d): ", i + 1);
        scanf("%d", &p[i].coeff);
        printf("Enter the exponent(%d): ", i + 1);
        scanf("%d", &p[i].expo);
    }

    return terms;
}

void displayPoly(struct poly p[10], int terms) {
    int k;

    for (k = 0; k < terms - 1; k++)
        printf("%d(x^%d) + ", p[k].coeff, p[k].expo);

    printf("%d(x^%d)\n", p[terms - 1].coeff, p[terms - 1].expo);
}

int addPoly(struct poly pl[10], struct poly p2[10], int t1, int t2, struct poly p3[10]) {
    int i = 0, j = 0, k = 0;

    while (i < t1 && j < t2) {
        if (pl[i].expo == p2[j].expo) {
            p3[k].coeff = pl[i].coeff + p2[j].coeff;
            p3[k].expo = pl[i].expo;
            i++, j++, k++;
        } else if (pl[i].expo > p2[j].expo) {
            p3[k].coeff = pl[i].coeff;
            p3[k].expo = pl[i].expo;
            i++, k++;
        } else {
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;
            j++, k++;
        }
    }

    // For remaining terms of polynomial 1
    while (i < t1) {
        p3[k].coeff = pl[i].coeff;
        p3[k].expo = pl[i].expo;
        i++, k++;
    }

    // For remaining terms of polynomial 2
    while (j < t2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        j++, k++;
    }

    return k;
}

