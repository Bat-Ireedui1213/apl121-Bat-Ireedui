
#include <stdio.h>

int main(void) {
    int guests, perPerson;
    int totalBuuz;
    int family[3];
    int i, j, temp;
    int dailyBuuz, remainder;
    double flour, meat, minutes;

    printf("=== TSAGAAN SARIIN BUUZ ===\n");

    /* 1. Zochdiin toog shalgah */
    do {
        printf("Zochdiin too (1-1000): ");
        if (scanf("%d", &guests) != 1) {
            printf("Buruu orolt! Buhel too oruulna uu.\n");
            return 1;
        }
    } while (guests < 1 || guests > 1000);

    /* 2. Neg hund nogdoh buuz */
    do {
        printf("Neg hund nogdoh buuz (1-100): ");
        if (scanf("%d", &perPerson) != 1) {
            printf("Buruu orolt! Buhel too oruulna uu.\n");
            return 1;
        }
    } while (perPerson < 1 || perPerson > 100);

    /* 3. Niit buuz ba orts */
    totalBuuz = guests * perPerson;

    flour = totalBuuz * 25.0 / 1000.0;
    meat = totalBuuz * 30.0 / 1000.0;
    minutes = totalBuuz * 20.0 / 100.0;

    printf("\n--- BUUZNY TOOTSOO ---\n");
    printf("Niit buuz: %d shirheg\n", totalBuuz);
    printf("Guril: %.2f kg\n", flour);
    printf("Mah: %.2f kg\n", meat);
    printf("Belteh hugatsaa: %.0f minut\n", minutes);

    /* 4. Buuzny hemjeegeer angilah */
    if (totalBuuz <= 100) {
        printf("Angilal: Baga hemjee\n");
    } else if (totalBuuz <= 500) {
        printf("Angilal: Dund hemjee\n");
    } else {
        printf("Angilal: Ih hemjee\n");
    }

    /* 5. Shiniin 1-5-nii husnegt */
    dailyBuuz = totalBuuz / 5;
    remainder = totalBuuz % 5;

    printf("\n--- SHINIIN 1-5-NII HUSNEGT ---\n");
    printf("%-12s %10s\n", "Ud ur", "Buuz");

    for (i = 1; i <= 5; i++) {
        int today = dailyBuuz;
        if (i <= remainder) {
            today++;
        }
        printf("%-12d %10d\n", i, today);
    }

    /* 6. Gurvan ailyn buuznii too */
    printf("\n--- GURVAN AIL ---\n");

    for (i = 0; i < 3; i++) {
        do {
            printf("%d-r ailyn buuznii too (1-100000): ", i + 1);
            if (scanf("%d", &family[i]) != 1) {
                printf("Buruu orolt! Buhel too oruulna uu.\n");
                return 1;
            }
        } while (family[i] < 1 || family[i] > 100000);
    }

    /* Ihesees baga ruu erembleh */
    for (i = 0; i < 2; i++) {
        for (j = i + 1; j < 3; j++) {
            if (family[i] < family[j]) {
                temp = family[i];
                family[i] = family[j];
                family[j] = temp;
            }
        }
    }

    printf("\nIhesees baga ruu:\n");
    for (i = 0; i < 3; i++) {
        printf("%d-r bair: %d buuz\n", i + 1, family[i]);
    }

    /* Arithmetic ba logic uildliin jishee */
    if (guests >= 1 && guests <= 1000) {
        printf("\nZochdiin orolt zuv baina.\n");
    }

    printf("Program duuslaa.\n");

    return 0;
}
