#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct list_element
{ //IDK type
    void *data;
    struct list_element *prev;
    struct list_element *next;
};
struct list
{
    struct list_element *head;
};

void init_list_element(struct list_element *elem)
{
    elem->data = NULL;
    elem->next = NULL;
    elem->prev = NULL;
}
void init_list(struct list *list)
{
    list->head = NULL;
}
struct list_element *get_last_list_element(struct list_element *head)
{
    struct list_element *cur = head;
    while (cur != NULL)
    {
        if (cur->next == NULL)
            break;

        cur = cur->next;
    }

    return cur;
}
void remove_list_element(struct list* list,struct list_element *elem)
{
    if(list->head == elem)
    {
        list->head = elem->next;
    }
    else
    {
    assert(elem->prev != NULL);
    elem->prev->next = elem->next;
    //elem = us
    //elem->prev = elem previous us
    //elem->prev->next = us
    }
    free(elem);
}
struct list_element *add_list_element(struct list *list, void *data)
{
   
    if(list->head == NULL)
    {
        list->head = (struct list_element*) malloc(sizeof(struct list_element));
        init_list_element(list->head);
        list->head->data = data;
        return  list->head;

    }

    struct list_element *last_elem = get_last_list_element(list->head);
    struct list_element *elem = (struct list_element *)malloc(sizeof(struct list_element));
    init_list_element(elem);
    elem->data = data;
    last_elem->next = elem;
    elem->prev = last_elem;
    return elem;
}
void destruct_list(struct list_element *head)
{
    struct list_element *cur = head->next;
    while (cur != NULL)
    {
        struct list_element *next = cur->next;
        free(cur);
        cur = next;
    }
}
int main(int argc, char **argv)
{
    struct list list;
    init_list(&list);
    struct list_element *first_element = add_list_element(&list, "First element");
     struct list_element *second_element = add_list_element(&list, "Second element");
      struct list_element *third_element = add_list_element(&list, "Third element");
      //\\\//\\\\\///////
      remove_list_element(&list, first_element);


         struct list_element *cur = list.head;
    while (cur != NULL)
    {
        printf("%s\n", (const char *)cur->data);
        cur = cur->next;
    }


 
    /*  struct list_element head;

    //Initialize list head
    init_list_element(&head);
    //add the first element to the list
    struct list_element *hello_world = add_list_element(&head, "Hello World");
    //Add the second element to the list
    struct list_element *second_element = add_list_element(&head, "Second Element");
    //Third element
    struct list_element *third_element = add_list_element(&head, "Third element ");

    remove_list_element(third_element);

    struct list_element *cur = &head;
    while (cur != NULL)
    {
        printf("%s\n", (const char *)cur->data);
        cur = cur->next;
    }

    /*
      struct list_element *cur2 = get_last_list_element(&head);
    while (cur2 != NULL)
    {
        printf("%s\n", (const char *)cur2->data);
        cur2 = cur2->prev;
    } 

    destruct_list(&head);
    */
    return 0;
}