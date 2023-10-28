#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char isim[100];
    struct Node* next;
};

void enuzunisim(struct Node* head) {
    if (head == NULL) {
        printf("Liste bos.\n");
        return;
    }

    struct Node* current = head;
    char enuzunisim[50];
    strcpy(enuzunisim, head->isim);

    while (current != NULL) {
        if (strlen(current->isim) > strlen(enuzunisim)) {
            strcpy(enuzunisim, current->isim);
        }
        current = current->next;
    }

    printf("En uzun isim: %s\n", enuzunisim);
}

void ekle(struct Node** head, char isim[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->isim, isim);
    newNode->next = *head;
    *head = newNode;
}

int main() {
    struct Node* head = NULL;

    // örnek liste
    ekle(&head, "ahmet");
    ekle(&head, "mehmet");
    ekle(&head, "ayse");
    ekle(&head, "fatma");
    ekle(&head, "mustafa");
    ekle(&head, "sarp");
    ekle(&head, "abdurrahmangazi");
    ekle(&head, "jale");
    ekle(&head, "helin");
    ekle(&head, "selin");
    ekle(&head, "idil");
    ekle(&head, "mert");
    ekle(&head, "furkan");
    ekle(&head, "samet");
    ekle(&head, "feyza");



    // fonksiyonu cagir
    enuzunisim(head);

    // bellekten ayrilan alani serbest birak
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

