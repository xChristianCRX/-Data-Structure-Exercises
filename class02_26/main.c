#include <stdio.h>
#include "ordered_list.h"

int main()
{
    t_ordered_list *list;
    t_ordered_list *list2;
    list = create_ordered_list(3);
    list2 = create_ordered_list(4);
    
    insert(list, 1);
    insert(list, 3);
    insert(list, 5);
    insert(list, 7);
    insert(list2, 2);
    insert(list2, 4);
    insert(list2, 6);
    insert(list2, 8);
    insert(list2, 10);
    
    t_ordered_list *list3 = merge(list, list2);
    print_ordered_list(list);
    print_ordered_list(list2);
    print_ordered_list(list3);
}