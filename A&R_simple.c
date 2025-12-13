#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITEM_NAME_MAX 64
#define LINE_BUF 256

static void print_summary(void) {
    FILE *f = fopen("inventory.txt", "r");
    if (!f) { printf("No inventory.txt found.\n"); return; }

    char line[LINE_BUF];
    size_t skus = 0;
    size_t units = 0;
    double total = 0.0;
    while (fgets(line, sizeof(line), f)) {
        int id, qty;
        double price;
        char name[ITEM_NAME_MAX];
        if (sscanf(line, "%d,%63[^,],%lf,%d", &id, name, &price, &qty) != 4) continue;
        skus++;
        units += (size_t)qty;
        total += price * qty;
    }
    fclose(f);
    printf("SKUs: %zu  Units: %zu  Total value: $%.2f\n", skus, units, total);
}

static void print_low_stock(int threshold) {
    FILE *f = fopen("inventory.txt", "r");
    if (!f) { printf("No inventory.txt found.\n"); return; }

    char line[LINE_BUF];
    int found = 0;
    while (fgets(line, sizeof(line), f)) {
        int id, qty;
        double price;
        char name[ITEM_NAME_MAX];
        if (sscanf(line, "%d,%63[^,],%lf,%d", &id, name, &price, &qty) != 4) continue;
        if (qty <= threshold) {
            printf("%d - %s (qty %d)\n", id, name, qty);
            found = 1;
        }
    }
    fclose(f);
    if (!found) printf("None (threshold %d)\n", threshold);
}

void analysis_menu_simple(void) {
    for (;;) {
        printf("\nAnalysis & Reports\n");
        printf("1) Summary\n2) Low-stock\n3) Back\n");
        printf("Choice: ");
        int choice = 0;
        if (scanf("%d", &choice) != 1) { while (getchar() != '\n'); continue; }
        while (getchar() != '\n'); /* flush rest of line */
        if (choice == 3) break;

        if (choice == 1) {
            print_summary();
        } else if (choice == 2) {
            printf("Threshold (default 5): ");
            int th = 5;
            if (scanf("%d", &th) != 1) th = 5;
            while (getchar() != '\n');
            print_low_stock(th);
        } else {
            printf("Invalid option.\n");
        }

        printf("\nPress Enter to continue...");
        while (getchar() != '\n');
    }
}
