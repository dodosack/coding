        #include <stdio.h>
        #include <stdlib.h>

        typedef struct Node
        {
            int data;
            int priority;
            struct Node *next_element;
        } Node;

        Node *add_new_Element(int priority, int data);                  // hinzufügen und sortieren
        void add_new_element_void(Node **head, int priority, int data); // Müssen den Pointer head aendern deswegen doppelpointer

        // neue elemte kommen vor alten und prio =0 ist das höchste und % das niedrigste
        void delete_Elements(Node **head, int priority); // löscht alle elemente einer priorität
        void free_all(Node **head);                      // löscht alles
        void display(Node *head);

        int main()
        {

            Node *head = NULL; // leere liste
            add_new_element_void(&head, 0, 100);
            add_new_element_void(&head, 2, 200);
            add_new_element_void(&head, 0, 11100);
            display(head);
            free_all(&head);
            return 0;
        }

        void add_new_element_void(Node **head, int priority, int data)
        {
            Node *new_node = add_new_Element(priority, data);

            Node *current = *head;
            if ((*head) == NULL) // leere liste also erstes element dann ist keine überprüfung nötig
            {
                (*head) = new_node;
                return;
            }

            else if (priority <= (*head)->priority) // erste stelle
            {
                new_node->next_element = (*head);
                *head = new_node;
                return;
            }
            while (current->next_element != NULL && !(priority <= current->next_element->priority)) // finde richitfe stelle zu einsetzen
            {
                current = current->next_element;
            } // ende oder mitten der lsite in einer logik
            new_node->next_element = current->next_element;
            current->next_element = new_node;
            return;
        };

        Node *add_new_Element(int priority, int data)
        {

            Node *new_Node = (Node *)malloc(sizeof(Node)); // speicher im heap
            if (new_Node == NULL)
            {
                printf("Fehler in der Speicherzuweisung");
                return NULL;
            }

            new_Node->data = data;
            new_Node->priority = priority;
            new_Node->next_element = NULL;
            return new_Node;
        };

        // neue elemte kommen vor alten und prio =0 ist das höchste und % das niedrigste
        void delete_Elements(Node **head, int priority)
        {
            Node *current = *head;
            Node *prev = NULL;

            while (current != NULL)
            {
                if (current->priority == priority) // löschen
                {
                    Node *temp = current;
                    if (prev == NULL) // also kopf
                    {
                        *head = current->next_element;
                        
                        current = *head;
                        // prev bleibt NULL   /* code */
                    }
                    else{

                    // mitte oder ende löshen
                    prev->next_element = current->next_element;
                    current = prev->next_element;
                    }

                    free(temp);
                } // weiter travesieren
                else
                {

                    prev = current;
                    current = current->next_element;
                }
            }

        }; // löscht alle elemente einer priorität
        void free_all(Node **head)
        {
            Node *current = *head;
            while (current != NULL)
            {
                Node *temp = current->next_element;
                free(current);
                current = temp;
            }
            

        }; // löscht alles
        void display(Node *head)
        {

            Node *temp = head;

            while (temp != NULL)
            {
                printf("Deine daten sind %d und deine Priorität: %d\n", temp->data, temp->priority);
                temp = temp->next_element;
            }
        };
