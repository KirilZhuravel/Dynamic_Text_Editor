#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void AddText(char** ioppszText, int* iopnLength) {
    int nLen, nNewLen;
    char *pszNewText, *pszTemp;

    printf("Enter len: ");
    scanf("%d", &nLen);
    pszNewText = (char*)malloc((nLen + 1) * sizeof(char));
    
    printf("Enter text: ");
    scanf("%s", pszNewText);

    nNewLen = *iopnLength + nLen + 1;
    pszTemp = (char*)realloc(*ioppszText, nNewLen * sizeof(char));
    if (pszTemp == NULL) return;
    
    *ioppszText = pszTemp;

    if (*iopnLength == 0) {
        (*ioppszText)[0] = '\0';
    }

    strcat(*ioppszText, pszNewText);
    free(pszNewText);
    *iopnLength += nLen;
}

void UpdateText(char** ioppszText, int* iopnLength) {
    int nCutPoint, nTempLength, nNewTotalLen, nReallocLen;
    char *pszNewText, *pszTemp, *pszTempRealloc;

    printf("Enter cut point: ");
    scanf("%d", &nCutPoint);
    printf("Enter length: ");
    scanf("%d", &nTempLength);

    pszNewText = (char*)malloc((nTempLength + 1) * sizeof(char));
    printf("Enter text: ");
    scanf("%s", pszNewText);

    if (nCutPoint == *iopnLength) {
        nReallocLen = *iopnLength + nTempLength + 1;
        pszTemp = (char*)realloc(*ioppszText, nReallocLen * sizeof(char));
        *ioppszText = pszTemp;
        strcat(*ioppszText, pszNewText);
        *iopnLength += nTempLength;
    } 
    else if ((nCutPoint + nTempLength) >= *iopnLength) {
        nNewTotalLen = nCutPoint + nTempLength;
        pszTempRealloc = (char*)realloc(*ioppszText, (nNewTotalLen + 1) * sizeof(char));
        *ioppszText = pszTempRealloc;
        strcpy(*ioppszText + nCutPoint, pszNewText);
        *iopnLength = nNewTotalLen;
    } 
    else {
        strcpy(*ioppszText + nCutPoint, pszNewText);
        *iopnLength = nCutPoint + nTempLength;
        (*ioppszText)[*iopnLength] = '\0';
    }
    free(pszNewText);
}

void RemoveText(char** ioppszText, int* iopnLength) {
    int nCutPoint;
    char* pszTemp;

    printf("Enter cut point: ");
    scanf("%d", &nCutPoint);

    if (nCutPoint <= 0) return;

    if (nCutPoint >= *iopnLength) {
        *iopnLength = 0;
        if (*ioppszText != NULL) (*ioppszText)[0] = '\0';
    } else {
        *iopnLength = *iopnLength - nCutPoint;
        (*ioppszText)[*iopnLength] = '\0';
        pszTemp = (char*)realloc(*ioppszText, (*iopnLength + 1) * sizeof(char));
        if (pszTemp != NULL) *ioppszText = pszTemp;
    }
}

void SaveIntoFile(char* ipszText) {
    char szFilename[100];
    FILE* pfsFile;

    if (ipszText == NULL) {
        printf("Nothing to save.\n");
        return;
    }

    printf("Enter filename: ");
    scanf("%s", szFilename);

    pfsFile = fopen(szFilename, "w");
    if (pfsFile != NULL) {
        fprintf(pfsFile, "%s", ipszText);
        fclose(pfsFile);
        printf("Saved successfully.\n");
    }
}