#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ==========================================
// DATA STRUCTURES & GLOBALS
// ==========================================

#define ITEM_NAME_MAX 64
#define LINE_BUF 256
#define MAX_PRODUCTS 1000
#define DATA_FILENAME "inventory.dat"

typedef struct {
    int id;
    char name[ITEM_NAME_MAX];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

// ==========================================
// UTILITY FUNCTIONS
// ==========================================

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        printf("\033[H\033[J");
    #endif
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pause_execution() {
    printf("\nPress Enter to continue...");
    while (getchar() != '\n');
}

// ==========================================
// UI FUNCTIONS (from main_menu.c)
// ==========================================

void print_login_menu() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Login Menu               |\n");
  printf("+========================================+\n");
  printf("|                                        |\n");
  printf("|  [ADMIN]                               |\n");
  printf("|     1. Login                           |\n");
  printf("|                                        |\n");
  printf("|  [USER]                                |\n");
  printf("|     2. Guest Mode                      |\n");
  printf("|                                        |\n");
  printf("|  [EXIT]                                |\n");
  printf("|     3. Exit                            |\n");
  printf("+========================================+\n");
  printf("Choice: ");
}

void print_admin_login() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Admin Login              |\n");
  printf("+========================================+\n");
  printf("\n");
}

void print_main_menu_admin() {
  printf("\n");
  printf("+========================================+\n");
  printf("|             Admin Dashboard            |\n");
  printf("+========================================+\n");
  printf("|                                        |\n");
  printf("|  [INVENTORY MANAGEMENT]                |\n");
  printf("|     1. Add Item                        |\n");
  printf("|     2. Remove Item                     |\n");
  printf("|     3. Update Item                     |\n");
  printf("|     4. Search Item                     |\n");
  printf("|     5. Display Inventory               |\n");
  printf("|                                        |\n");
  printf("|  [ANALYSIS & REPORTS]                  |\n");
  printf("|     6. Low Stock Items                 |\n");
  printf("|     7. Sort by Price                   |\n");
  printf("|     8. Inventory Summary               |\n");
  printf("|                                        |\n");
  printf("|  [EXIT]                                |\n");
  printf("|     9. Logout                          |\n");
  printf("+========================================+\n");
  printf("Choice: ");
}

void print_main_menu_user() {
  printf("\n");
  printf("+========================================+\n");
  printf("|              User Dashboard            |\n");
  printf("+========================================+\n");
  printf("|                                        |\n");
  printf("|  [INVENTORY BROWSING]                  |\n");
  printf("|     1. Search Item                     |\n");
  printf("|     2. Display Inventory               |\n");
  printf("|     3. Sort by Price                   |\n");
  printf("|                                        |\n");
  printf("|  [EXIT]                                |\n");
  printf("|     4. Logout                          |\n");
  printf("+========================================+\n");
  printf("Choice: ");
}

void print_add_item_header() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Add Item                 |\n");
  printf("+========================================+\n");
}

void print_remove_item_header() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Remove Item              |\n");
  printf("+========================================+\n");
}

void print_update_item_header() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Update Item              |\n");
  printf("+========================================+\n");
}

void print_search_header() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Search Item              |\n");
  printf("+========================================+\n");
}

void print_display_header() {
  printf("\n");
  printf("+=========================================+\n");
  printf("|              Display Inventory          |\n");
  printf("+=========================================+\n");
}

void print_low_stock_header() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Low Stock Items          |\n");
  printf("+========================================+\n");
}

void print_sort_header() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Sort by Price            |\n");
  printf("+========================================+\n");
}

void print_summary_header() {
    printf("\n");
    printf("+========================================+\n");
    printf("|           Inventory Summary            |\n");
    printf("+========================================+\n");
}

void print_table_header() {
    printf("\n");
    printf("+======+================================+==========+============+\n");
    printf("| %-4s | %-30s | %-8s | %-10s |\n", "ID", "Name", "Quantity", "Price");
    printf("+======+================================+==========+============+\n");
}

void print_table_footer() {
    printf("+======+================================+==========+============+\n");
}

void print_product_row(int id, char *name, int qty, float price) {
    printf("| %-4d | %-30s | %-8d | $%-9.2f |\n", id, name, qty, price);
}

// ==========================================
// FILE OPERATIONS
// ==========================================

void loadFromFile() {
    FILE *file = fopen(DATA_FILENAME, "rb");
    if (file == NULL) {
        return;
    }

    fread(&productCount, sizeof(int), 1, file);
    if (productCount > MAX_PRODUCTS) productCount = MAX_PRODUCTS;
    fread(inventory, sizeof(Product), productCount, file);

    fclose(file);
}

void saveToFile() {
    FILE *file = fopen(DATA_FILENAME, "wb");
    if (file == NULL) {
        printf("Error: Could not save data to %s\n", DATA_FILENAME);
        return;
    }

    fwrite(&productCount, sizeof(int), 1, file);
    fwrite(inventory, sizeof(Product), productCount, file);

    fclose(file);
    printf("Data saved successfully.\n");
}

// ==========================================
// CORE LOGIC
// ==========================================

int generateID() {
    int maxID = 0;
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id > maxID) maxID = inventory[i].id;
    }
    return maxID + 1;
}

int findIndexByID(int id) {
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) return i;
    }
    return -1;
}

void addProduct() {
    clear_screen();
    print_add_item_header();

    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        pause_execution();
        return;
    }

    Product p;
    p.id = generateID();
    printf("Generated ID: %d\n", p.id);

    printf("Enter item name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0;

    printf("Enter quantity: ");
    if (scanf("%d", &p.quantity) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        pause_execution();
        return;
    }

    printf("Enter price: ");
    if (scanf("%f", &p.price) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        pause_execution();
        return;
    }
    clearInputBuffer();

    inventory[productCount++] = p;
    printf("\nItem added successfully!\n");
    pause_execution();
}

void deleteProduct() {
    clear_screen();
    print_remove_item_header();

    int id;
    printf("Enter item ID to remove: ");
    if (scanf("%d", &id) != 1) {
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    int idx = findIndexByID(id);
    if (idx == -1) {
        printf("Item not found.\n");
    } else {
        printf("Deleting: %s\n", inventory[idx].name);
        printf("Are you sure? (y/n): ");
        char c = getchar();
        clearInputBuffer();
        if (c == 'y' || c == 'Y') {
            for (int i = idx; i < productCount - 1; i++) {
                inventory[i] = inventory[i+1];
            }
            productCount--;
            printf("Item deleted.\n");
        } else {
            printf("Cancelled.\n");
        }
    }
    pause_execution();
}

void updateProduct() {
    clear_screen();
    print_update_item_header();

    int id;
    printf("Enter item ID to update: ");
    if (scanf("%d", &id) != 1) {
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    int idx = findIndexByID(id);
    if (idx == -1) {
        printf("Item not found.\n");
        pause_execution();
        return;
    }

    Product *p = &inventory[idx];
    printf("Updating: %s (Qty: %d, Price: %.2f)\n", p->name, p->quantity, p->price);
    
    printf("Enter new name (current: %s): ", p->name);
    char buf[ITEM_NAME_MAX];
    fgets(buf, sizeof(buf), stdin);
    if (buf[0] != '\n') {
        buf[strcspn(buf, "\n")] = 0;
        strcpy(p->name, buf);
    }

    printf("Enter new quantity (current: %d): ", p->quantity);
    int qty_in;
    char line[64];
    fgets(line, sizeof(line), stdin);
    if (line[0] != '\n') {
        if (sscanf(line, "%d", &qty_in) == 1) p->quantity = qty_in;
    }

    printf("Enter new price (current: %.2f): ", p->price);
    float price_in;
    fgets(line, sizeof(line), stdin);
    if (line[0] != '\n') {
        if (sscanf(line, "%f", &price_in) == 1) p->price = price_in;
    }

    printf("Item updated.\n");
    pause_execution();
}

void displayInventory() {
    clear_screen();
    print_display_header();
    print_table_header();
    for (int i = 0; i < productCount; i++) {
        print_product_row(inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    print_table_footer();
    printf("\nTotal Items: %d\n", productCount);
    pause_execution();
}

void searchProduct() {
    clear_screen();
    print_search_header();

    printf("Enter item ID or Name: ");
    char query[128];
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = 0;

    int is_id = 1;
    for (int i = 0; query[i]; i++) {
        if (!isdigit((unsigned char)query[i])) {
            is_id = 0;
            break;
        }
    }

    print_table_header();
    int found = 0;
    if (is_id && strlen(query) > 0) {
        int id = atoi(query);
        for (int i = 0; i < productCount; i++) {
            if (inventory[i].id == id) {
                print_product_row(inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                found = 1;
            }
        }
    } else {
        for (int i = 0; i < productCount; i++) {
            char name_lower[ITEM_NAME_MAX]; 
            char query_lower[128];
            strcpy(name_lower, inventory[i].name);
            strcpy(query_lower, query);
            
            for(int j=0; name_lower[j]; j++) name_lower[j] = tolower((unsigned char)name_lower[j]);
            for(int j=0; query_lower[j]; j++) query_lower[j] = tolower((unsigned char)query_lower[j]);

            if (strstr(name_lower, query_lower)) {
                print_product_row(inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                found = 1;
            }
        }
    }
    if (found) print_table_footer();

    if (!found) printf("No matching items found.\n");
    pause_execution();
}

// ==========================================
// ANALYSIS FUNCTIONS
// ==========================================

void printSummary() {
    clear_screen();
    print_summary_header();
    
    size_t units = 0;
    double totalValue = 0.0;

    for (int i = 0; i < productCount; i++) {
        units += inventory[i].quantity;
        totalValue += inventory[i].quantity * inventory[i].price;
    }

    printf("\nTotal SKUs:    %d\n", productCount);
    printf("Total Units:   %zu\n", units);
    printf("Total Value:   $%.2f\n", totalValue);
    
    pause_execution();
}

void printLowStock() {
    clear_screen();
    print_low_stock_header();

    int threshold = 5;
    printf("Enter low stock threshold (default 5): ");
    char line[64];
    fgets(line, sizeof(line), stdin);
    if (line[0] != '\n') {
        int tmp;
        if (sscanf(line, "%d", &tmp) == 1) threshold = tmp;
    }

    print_table_header();
    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].quantity <= threshold) {
            print_product_row(inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
        }
    }
    if (found) print_table_footer();
    if (!found) printf("No items below threshold %d.\n", threshold);
    pause_execution();
}

void sortByPrice() {
    clear_screen();
    print_sort_header();

    for (int i = 0; i < productCount - 1; i++) {
        for (int j = 0; j < productCount - i - 1; j++) {
            if (inventory[j].price > inventory[j+1].price) {
                Product temp = inventory[j];
                inventory[j] = inventory[j+1];
                inventory[j+1] = temp;
            }
        }
    }
    printf("Inventory sorted by price (ascending).\n");
    displayInventory();
}

// ==========================================
// MAIN LOOP
// ==========================================

int main() {
    loadFromFile();
    
    while(1) {
        clear_screen();
        print_login_menu();
        
        int choice;
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        if (choice == 3) {
            break;
        } 
        else if (choice == 1) {
            clear_screen();
            print_admin_login();
            
            char user[64], pass[64];
            printf("Username: ");
            fgets(user, sizeof(user), stdin);
            user[strcspn(user, "\n")] = 0;
            printf("Password: ");
            fgets(pass, sizeof(pass), stdin);
            pass[strcspn(pass, "\n")] = 0;

            if (strcmp(user, "admin") == 0 && strcmp(pass, "admin123") == 0) {
                while(1) {
                    clear_screen();
                    print_main_menu_admin();
                    if (scanf("%d", &choice) != 1) { clearInputBuffer(); continue; }
                    clearInputBuffer();

                    if (choice == 1) addProduct();
                    else if (choice == 2) deleteProduct();
                    else if (choice == 3) updateProduct();
                    else if (choice == 4) searchProduct();
                    else if (choice == 5) displayInventory();
                    else if (choice == 6) printLowStock();
                    else if (choice == 7) sortByPrice();
                    else if (choice == 8) printSummary();
                    else if (choice == 9) { saveToFile(); break; }
                }
            } else {
                printf("Invalid credentials.\n");
                pause_execution();
            }
        } 
        else if (choice == 2) {
             while(1) {
                clear_screen();
                print_main_menu_user();
                if (scanf("%d", &choice) != 1) { clearInputBuffer(); continue; }
                clearInputBuffer();

                if (choice == 1) searchProduct();
                else if (choice == 2) displayInventory();
                else if (choice == 3) sortByPrice();
                else if (choice == 4) break;
            }
        }
    }

    saveToFile();
    printf("Goodbye!\n");
    return 0;
}
