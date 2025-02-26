#include <stdio.h>
#include <stdlib.h>
#include"ordered_list.h"

t_ordered_list* create_ordered_list(int max){
    t_ordered_list *list = (t_ordered_list*)malloc(sizeof(t_ordered_list));
    list->max = max;
    list->n = 0;
    list->items = (int *)malloc(sizeof(int) * max);

    return list;
};

int size(t_ordered_list* list){
    return list->n;
};

int is_empty(t_ordered_list* list){
    return list->n <= 0;
};

int is_full(t_ordered_list* list){
    return list->n >= list->max;
};

void destroy(t_ordered_list* list){
    free(list->items);
    free(list);
};

void clear(t_ordered_list* list){
    list->n = 0;
};

int insert(t_ordered_list* list, int value){
    if(list->n >= list->max){
        list->items = realloc(list->items, list->max+1 * sizeof(int));
        list->max++;
    }

    if(value > list->items[list->n-1])
        list->items[list->n++] = value;
    else{
        for(int b = list->n; b > 0; b--){
            if(value < list->items[b]){
                list->items[b] = list->items[b-1];                   
            }else{
                list->items[b] = value;
                list->n++;
                break; 
            }
        }
    }
}

int search(t_ordered_list* list, int value){
    for(int i = 0; i < list->n; i++){
        if(list->items[i] == value) return i;
    }

    return -1;
};

int remove_by_index(t_ordered_list* list, int index){
    if(index >= list->n) return 0;

    for(int i = index; i < list->n-1; i++){
        list->items[i] = list->items[i+1];
    }
    list->n--;
    return 1;
};

int remove_by_value(t_ordered_list* list, int value){
    for(int i = 0; i < list->n-1; i++){
        if(list->items[i] == value){
            for(int j = i; j < list->n-1; j++){
                list->items[j] = list->items[j+1];
            }
            list->n--;
            return 1;
        }
    }

    return 0;
};

int remove_end(t_ordered_list* list){
    if(is_empty(list)) return 0;

    list->n--;
    return 1;
};

void print_ordered_list(t_ordered_list* list){
    printf("\n");
    for(int i = 0; i < list->n; i++){
        printf("%d ", list->items[i]);
    }
    printf("\n");
    printf("\n");
};

t_ordered_list* merge(t_ordered_list* list1, t_ordered_list* list2){
    t_ordered_list* list3 = create_ordered_list(list1->max + list2->max);
    int index1 = 0, index2 = 0, index3 = 0;
    while(index1 < list1->n && index2 < list2->n){
        if(list1->items[index1] > list2->items[index2]){
            list3->items[index3++] = list2->items[index2++];
        }else{
            list3->items[index3++] = list1->items[index1++];
        }
    }

    while(index1 < list1->n){
        list3->items[index3++] = list1->items[index1++];
    }
    while(index2 < list2->n){
        list3->items[index3++] = list2->items[index2++];
    }

    list3->n = index3;
    return list3;
}