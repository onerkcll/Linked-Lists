#include <stdio.h>
#include <stdlib.h>
struct list_element
{ //IDK type
    void *data;
    struct list_element *next;
    struct list_element *prev;
};

void init_list_element(struct list_element *elem)
{
    elem->data = NULL;
    elem->next = NULL;
    elem->prev = NULL;
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
void remove_list_element(struct list_element* elem)
{   //exmp: 3->2->3 = 2->4 it'll pass 3 
    elem->prev->next = elem->next;
    //elem = us
    // elem->prev = element previous to us 
    // elem->prev->next us 
    free(elem);
}
struct list_element* add_list_element(struct list_element *head, void *data)
{
    struct list_element* result = NULL;
    if (head->data == NULL)
    {
        head->data = data;
        result = head;
    }
    else
    { //control
        struct list_element *last_elem = get_last_list_element(head);
        struct list_element *elem = (struct list_element *)malloc(sizeof(struct list_element));
        init_list_element(elem);
        elem->data = data;
        elem->prev = last_elem;
        last_elem->next = elem;
        result = elem;
    }
   return result;
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

    struct list_element head;

    //Initialize list head
    init_list_element(&head);
    //add the first element to the list
   struct list_element* hello_world = add_list_element(&head, "Hello World");
    //Add the second element to the list
    struct list_element* second_element = add_list_element(&head, "Second Element");
    //Third element
    struct list_element* third_element = add_list_element(&head, "Third element ");
    //if u put hello world it will crash because it is not in heap its in stack and our main element
    remove_list_element(third_element);
/*
    struct list_element *cur = get_last_list_element(&head);
    while (cur != NULL)
    {
        printf("%s\n", (const char *)cur->data);
        cur = cur->prev;
    }
*/
    struct list_element *cur2 = &head;
    while (cur2 != NULL)
    {
        printf("%s\n", (const char *)cur2->data);
        cur2 = cur2->next;
    }
    //clean up memory
    destruct_list(&head);
    getchar();
    return 0;
}