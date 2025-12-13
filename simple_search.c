#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void search_item() {
    char q[128];
    printf("\n+========================================+\n");
    printf("|               Search Item              |\n");
    printf("+========================================+\n\n");
    printf("Enter item ID or name: ");
    if (!fgets(q, sizeof q, stdin)) return;
    q[strcspn(q, "\r\n")] = '\0';
    if (q[0] == '\0') { printf("Empty query.\n"); return; }

    int is_id = 1;
    for (char *p = q; *p; ++p) if (!isdigit((unsigned char)*p)) { is_id = 0; break; }

    FILE *f = fopen("inventory.txt", "r");
    if (!f) { printf("No inventory.txt found.\n"); return; }

    char line[256];
    int found = 0;
    while (fgets(line, sizeof line, f)) {
        int id = 0, qty = 0;
        double price = 0.0;
        char name[128] = {0};
        if (sscanf(line, "%d,%127[^,],%lf,%d", &id, name, &price, &qty) != 4) continue;

        if (is_id) {
            if (id == atoi(q)) { 
                printf("ID: %d  Name: %s  Price: $%.2f  Qty: %d\n", id, name, price, qty);
                found = 1;
                break; /* stop after ID match */
            }
        } else {
            char nl[128], ql[128];
            strncpy(nl, name, sizeof nl - 1); nl[sizeof nl - 1] = '\0';
            strncpy(ql, q, sizeof ql - 1); ql[sizeof ql - 1] = '\0';
            for (char *t = nl; *t; ++t) *t = (char)tolower((unsigned char)*t);
            for (char *t = ql; *t; ++t) *t = (char)tolower((unsigned char)*t);
            if (strstr(nl, ql)) {
                printf("ID: %d  Name: %s  Price: $%.2f  Qty: %d\n", id, name, price, qty);
                found = 1;
            }
        }
    }

    fclose(f);
    if (!found) printf("No match found.\n");
}
