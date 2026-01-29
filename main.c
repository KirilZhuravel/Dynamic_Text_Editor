#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void) {
    char* pszText = NULL;
    int nLength = 0;
    int nChoice = 0;

    while (nChoice != 6) {
        printf("\n--- Dynamic Text Editor ---\n");
        printf("1. Add Text\n2. Update Text\n3. Delete Text\n");
        printf("4. Print Current Text\n5. Save to File\n6. Exit\n");
        printf("Choice: ");
        scanf("%d", &nChoice);

        switch (nChoice) {
            case 1: AddText(&pszText, &nLength); break;
            case 2: UpdateText(&pszText, &nLength); break;
            case 3: RemoveText(&pszText, &nLength); break;
            case 4: 
                printf("Text: %s\n", (pszText ? pszText : "(empty)")); 
                break;
            case 5: SaveIntoFile(pszText); break;
            case 6: 
                printf("Exiting...\n"); 
                if (pszText) free(pszText);
                break;
            default: printf("Incorrect choice!\n"); break;
        }
    }
    return 0;
}