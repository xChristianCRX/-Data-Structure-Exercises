#include <stdio.h>
#include "ordered_list.h"

int main()
{
    t_ordered_list *list;
    t_ordered_list *list2;
    list = create_ordered_list(3);
    list2 = create_ordered_list(10);

    insert(list, 7);
    insert(list, 4);
    insert(list, 2);
    insert(list, 3);
    print_ordered_list(list);
    printf("SIZE: %d\n", size(list));

    insert(list2, 10);
    insert(list2, 6);
    insert(list2, 5);
    insert(list2, 1);
    print_ordered_list(list2);
    printf("SIZE: %d\n", size(list2));
    
    printf("SEARCH: %d\n", search(list, 3));
    
    remove_by_index(list2, 2);
    printf("SIZE: %d\n", size(list2));
    print_ordered_list(list2);

    t_ordered_list *list3;
    list3 = merge(list, list2);
    print_ordered_list(list3);
}