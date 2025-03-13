    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <assert.h>

    typedef struct Node
    {
        int data;
        int priority;
        struct Node *next;
    } Node;
    typedef Node *ptr_node;

    ptr_node create(int data, int priority);
    void add(ptr_node *head, int data, int priority);
    void delete_by_data(ptr_node *head, int data_to_delete);
    void search(ptr_node head, int data_to_search);
    void display(ptr_node head);
    void clear(ptr_node *);

    int main()
    {
        ptr_node head = NULL; // leere liste
        add(&head, 100, 1);
        add(&head, 102, 1);
        add(&head, 1007, 7);

        add(&head, 104, 7);
        search(head, 100);
        search(head, 100);
        delete_by_data(&head, 100);

        delete_by_data(&head, 100);
        display(head);
        clear(&head);
        return 0;
    }

    ptr_node create(int data, int priority)
    {
        ptr_node new_node = (ptr_node)malloc(sizeof(Node));
        if (new_node == NULL)
        {
            printf("Fehler  in der speicher allokierung in der create func\n");
            exit(1);
        }

        new_node->data = data;
        new_node->priority = priority;
        new_node->next = NULL;
        return new_node;
    };
    void add(ptr_node *head, int data, int priority)
    {
        ptr_node new = create(data, priority);

        if (*head == NULL || (*head)->priority > priority)
        {
            new->next = *head;
            *head = new;
            return;
        }
        ptr_node current = *head;
        while (current->next != NULL)
        {
            if (current->next->priority > priority)
            {
                new->next = current->next;
                current->next = new;
                return;
            }
            //  sonst weiter
            current = current->next;
        }
        // sonst am ende
        current->next = new;
    };
    void delete_by_data(ptr_node *head, int data_to_delete)
    {

        if (*head == NULL)
        {
            printf("Liste bereits leer\n");
            return;
        }
        if ((*head)->data == data_to_delete)
        {
            ptr_node temp = *head;
            *head = (*head)->next;
            free(temp);
            printf("Knoten mit daten %d gelöscht", data_to_delete);

            return;
        }
        if (*head == NULL)
        {
            printf("Liste ist nun Leer nach löschung");
        }
        bool flag = false;

        ptr_node current = *head;
        while (current->next != NULL)
        {
            if (current->next->data == data_to_delete)
            {
                ptr_node temp = current->next;
                current->next = current->next->next;
                free(temp);
                printf("Knoten mt den daten %d gelöschtt!\n", data_to_delete);
                flag = true;
                return;
            }
            current = current->next;
        }

        printf("Keinen Knoten gefunden\n");
    };
    void search(ptr_node head, int data_to_search)
    {

        if (head == NULL)
        {
            printf("Liste ist leer, keinen passenendn knoten\n");
            return;
        }
        ptr_node current = head;
        while (current != NULL)
        {
            if (current->data == data_to_search)
            {
                printf("GEfunden deine daten  %d mit prio %d\n ", data_to_search, current->priority);
                return; // kann abgebroichen  werden um laufzeit zu sparen
            }
            current = current->next;
        }
        printf("keine daten gefundn;´\n");
    };
    void display(ptr_node head)
    {
        if (head == NULL)
        {
            printf("Liste leer\n");
            return;
        }
        printf("Start\n");
        ptr_node current = head;
        while (current != NULL)
        {
            printf("Deine deten und deine prio\n", current->data, current->priority);
            current = current->next;
        }
        printf("ENde");
    };
    void clear(ptr_node *head)
    {
        if (*head == NULL)
        {
            printf("Lsite bereits leer\n");
            return;
        }
        ptr_node current = *head;
        while (current != NULL)
        {
            ptr_node temp = current;
            current = current->next;
            free(temp);

            /* code */
        }
        *head = NULL;
        printf("Liste gelöscht\n");
    };