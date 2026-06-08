#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_CURRENCIES 8

struct Currency {
    char code[4];
    char name[30];
    double rate;
};

typedef struct Currency Currency;

void initialize_currencies(Currency currencies[]) {
    strcpy(currencies[0].code, "USD");
    strcpy(currencies[0].name, "US Dollar");
    currencies[0].rate = 92.3500;

    strcpy(currencies[1].code, "EUR");
    strcpy(currencies[1].name, "Euro");
    currencies[1].rate = 100.1500;

    strcpy(currencies[2].code, "GBP");
    strcpy(currencies[2].name, "British Pound");
    currencies[2].rate = 117.5000;

    strcpy(currencies[3].code, "CNY");
    strcpy(currencies[3].name, "Chinese Yuan");
    currencies[3].rate = 12.6500;

    strcpy(currencies[4].code, "JPY");
    strcpy(currencies[4].name, "Japanese Yen");
    currencies[4].rate = 0.6200;

    strcpy(currencies[5].code, "CHF");
    strcpy(currencies[5].name, "Swiss Franc");
    currencies[5].rate = 104.2000;

    strcpy(currencies[6].code, "TRY");
    strcpy(currencies[6].name, "Turkish Lira");
    currencies[6].rate = 2.8000;

    strcpy(currencies[7].code, "AED");
    strcpy(currencies[7].name, "UAE Dirham");
    currencies[7].rate = 25.1500;
}

void search_currency(const Currency currencies[], const char *input) {
    int found = 0;
    for (int i = 0; i < NUM_CURRENCIES; i++) {
        if (strcmp(currencies[i].code, input) == 0 ||
            strstr(currencies[i].name, input) != NULL) {
            printf("Found, %s (%s), %.4f RUB.\n",
                   currencies[i].code, currencies[i].name, currencies[i].rate);
            found = 1;
        }
    }
    if (!found) {
        printf("Not found.\n");
    }
}

int main() {
    Currency currencies[NUM_CURRENCIES];
    char input[50];

    initialize_currencies(currencies);

    printf("Enter currency code or name: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        }
    }

    search_currency(currencies, input);

    return 0;
}
