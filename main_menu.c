#include <stdio.h>

void login() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Login Menu               |\n");
  printf("+========================================+\n");
  printf("|                                        |\n");
  printf("|  [ADMIN]                               |\n");
  printf("|     1. Login                           |\n");
  printf("|                                        |\n");
  printf("|  [USER]                                |\n");
  printf("|     2. Register                        |\n");
  printf("|     3. Login                           |\n");
  printf("|                                        |\n");
  printf("|  [EXIT]                                |\n");
  printf("|     4. Exit                            |\n");
  printf("+========================================+\n");
}

void register_menu() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Register Menu            |\n");
  printf("+========================================+\n");
  printf("\n");
  printf("Enter your name: \n");
  printf("Enter your password: \n");
  printf("Confirm your password: \n");
}

void admin_login() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Admin Login              |\n");
  printf("+========================================+\n");
  printf("\n");
  printf("Enter your name: \n");
  printf("Enter your password: \n");
}

void user_login() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               User Login               |\n");
  printf("+========================================+\n");
  printf("\n");
  printf("Enter your name: \n");
  printf("Enter your password: \n");
}

void exit_menu() {
  // Exits to login screen
  printf("\n");
  printf("+========================================+\n");
  printf("|               Exit Menu                |\n");
  printf("+========================================+\n");
  printf("|                                        |\n");
  printf("|  [YES]                                 |\n");
  printf("|     1. Yes                             |\n");
  printf("|                                        |\n");
  printf("|  [NO]                                  |\n");
  printf("|     2. No                              |\n");
  printf("+========================================+\n");
}

void exit_program() {
  // Exits the program
  printf("\n");
  printf("+========================================+\n");
  printf("|               Exit Program             |\n");
  printf("+========================================+\n");
  printf("|                                        |\n");
  printf("|    [YES]                               |\n");
  printf("|      1. Yes                            |\n");
  printf("|                                        |\n");
  printf("|    [NO]                                |\n");
  printf("|      2. No                             |\n");
  printf("+========================================+\n");
}

void exit_msg() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Exit Message             |\n");
  printf("+========================================+\n");
  printf("|                                        |\n");
  printf("|    Thank you for using our program!    |\n");
  printf("|                                        |\n");
  printf("+========================================+\n");
}

void add_item() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Add Item                 |\n");
  printf("+========================================+\n");
  printf("\n");
  printf("Enter item ID: \n");
  printf("Enter item name: \n");
  printf("Enter item price: \n");
  printf("Enter item quantity: \n");
}

void remove_item() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Remove Item              |\n");
  printf("+========================================+\n");
  printf("\n");
  printf("Enter item ID: \n");
}

void update_item() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Update Item              |\n");
  printf("+========================================+\n");
  printf("\n");
  printf("Enter item ID: \n");
  printf("Enter item name: \n");
  printf("Enter item price: \n");
  printf("Enter item quantity: \n");
}

void search_item() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Search Item              |\n");
  printf("+========================================+\n");
  printf("\n");
  printf("Enter item ID: \n");
}

void display_inventory() {
  char *text = "";
  printf("\n");
  printf("+=========================================+\n");
  printf("|              Display Inventory          |\n");
  printf("+=========================================+\n");
  printf("\n");
  //   printf("ID: %d\n", 1);
  //   printf("Name: %s\n", "Item 1");
  //   printf("Price: %f\n", 10.00);
  //   printf("Quantity: %d\n", 10);
}

void low_stock_items() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Low Stock Items          |\n");
  printf("+========================================+\n");
  printf("\n");
  //   printf("ID: %d\n", 1);
  //   printf("Name: %s\n", "Item 1");
  //   printf("Price: %f\n", 10.00);
  //   printf("Quantity: %d\n", 10);
}

void sort_by_price() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Sort by Price            |\n");
  printf("+========================================+\n");
  printf("\n");
  //   printf("ID: %d\n", 1);
  //   printf("Name: %s\n", "Item 1");
  //   printf("Price: %f\n", 10.00);
  //   printf("Quantity: %d\n", 10);
}

void save_inventory() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Save Inventory           |\n");
  printf("+========================================+\n");
  printf("\n");
}

void load_inventory() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Load Inventory           |\n");
  printf("+========================================+\n");
  printf("\n");
}

void main_menu() {
  printf("\n");
  printf("+========================================+\n");
  printf("|               Main Menu                |\n");
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
  printf("|                                        |\n");
  printf("|  [FILE OPERATIONS]                     |\n");
  printf("|     8. Save Inventory                  |\n");
  printf("|     9. Load Inventory                  |\n");
  printf("|                                        |\n");
  printf("|  [EXIT]                                |\n");
  printf("|     10. Exit                           |\n");
  printf("+========================================+\n");
}