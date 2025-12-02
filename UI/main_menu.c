#include <stdio.h>
#include "../UTILS/move_cursor.h"
#include "../UTILS/more_fgets.h"

void display_main_menu()
{
    printf("+=====================================+\n");
    printf("|             MAIN MENU               |\n");
    printf("+=====================================+\n");
    printf("| [INVENTORY OPERATIONS]              |\n");
    printf("|    1. Add Item                      |\n");
    printf("|    2. Remove Item                   |\n");
    printf("|    3. Update Item                   |\n");
    printf("|    4. Search by ID                  |\n");
    printf("|    5. Search by Name                |\n");
    printf("|                                     |\n");
    printf("| [ANALYSIS & REPORTS]                |\n");
    printf("|    6. Low Stock Alerts              |\n");
    printf("|    7. Sort by Price                 |\n");
    printf("|    8. View Statistics               |\n");
    printf("|                                     |\n");
    printf("| [FILE OPERATIONS]                   |\n");
    printf("|    9. Save to File                  |\n");
    printf("|    10. Load from File               |\n");
    printf("|                                     |\n");
    printf("|    0. Exit                          |\n");
    printf("+=====================================+\n");
}

void add_item()
{
    int item_id;
    char item_name[100];
    float item_price;
    int item_quantity;
    printf("+=====================================+\n");
    printf("|             ADD ITEM                |\n");
    printf("+=====================================+\n");
    printf("| Enter Item ID:                      |\n");
    printf("| Enter Item Name:                    |\n");
    printf("| Enter Item Price:                   |\n");
    printf("| Enter Item Quantity:                |\n");
    printf("+=====================================+\n");
    gotoxy(18, 4);
    fgets_int(&item_id);
    gotoxy(20, 5);
    fgets_str(item_name, sizeof(item_name));
    gotoxy(21, 6);
    fgets_float(&item_price);
    gotoxy(24, 7);
    fgets_int(&item_quantity);
}

void remove_item()
{
    int item_id;
    printf("+=====================================+\n");
    printf("|             REMOVE ITEM             |\n");
    printf("+=====================================+\n");
    printf("| Enter Item ID:                      |\n");
    printf("+=====================================+\n");
    gotoxy(18, 4);
    fgets_int(&item_id);
}

void update_item()
{
    int item_id;
    char item_name[100];
    float item_price;
    int item_quantity;
    printf("+=====================================+\n");
    printf("|             UPDATE ITEM             |\n");
    printf("+=====================================+\n");
    printf("| Enter Item ID:                      |\n");
    printf("| Enter New Item Name:                |\n");
    printf("| Enter New Item Price:               |\n");
    printf("| Enter New Item Quantity:            |\n");
    printf("+=====================================+\n");
    gotoxy(18, 4);
    fgets_int(&item_id);
    gotoxy(24, 5);
    fgets_str(item_name, sizeof(item_name));
    gotoxy(25, 6);
    fgets_float(&item_price);
    gotoxy(28, 7);
    fgets_int(&item_quantity);
}

void search_by_id()
{
    int item_id;
    printf("+=====================================+\n");
    printf("|             SEARCH BY ID            |\n");
    printf("+=====================================+\n");
    printf("| Enter Item ID:                      |\n");
    printf("+=====================================+\n");
    gotoxy(18, 4);
    fgets_int(&item_id);
}

void search_by_name()
{
    char item_name[100];
    printf("+=====================================+\n");
    printf("|             SEARCH BY NAME          |\n");
    printf("+=====================================+\n");
    printf("| Enter Item Name:                    |\n");
    printf("+=====================================+\n");
    gotoxy(20, 4);
    fgets_str(item_name, sizeof(item_name));
}
