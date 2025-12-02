#include <stdio.h>
#include "UI/main_menu.h"
#include "UTILS/clear_screen.h"
#include "UTILS/move_cursor.h"

int main()
{
    clear_screen();
    display_main_menu();
    clear_screen();
    add_item();
    clear_screen();
    remove_item();
    clear_screen();
    update_item();
    clear_screen();
    search_by_id();
    clear_screen();
    search_by_name();
    clear_screen();
    return 0;
}