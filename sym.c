#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sym.h"

SymbolTableEntry* symbolTable = NULL;
ArrayTableEntry* arrayTable = NULL;

void initSymbolTable() {
    symbolTable = NULL;
}

int isSymbolPresent(char* name) {
    SymbolTableEntry* entry = symbolTable;

    while (entry != NULL) {
        if (strcmp(entry->name, name) == 0) {
            return 1; // Symbol found
        }
        entry = entry->next;
    }

    return 0; // Symbol not found
}

void insertSymbol(char* name, SymbolType type, SymbolValue value) {
    
    if (isSymbolPresent(name)) {
        
        // Symbol already present, update its value and return
        SymbolTableEntry* entry = symbolTable;
        while (entry != NULL) {
            if (strcmp(entry->name, name) == 0) {
                entry->value = value;
                return;
            }
            entry = entry->next;
        }
    }
    

    // Symbol not found, create a new entry
    SymbolTableEntry* newEntry = (SymbolTableEntry*)malloc(sizeof(SymbolTableEntry));
    if (newEntry == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newEntry->name = strdup(name);
    newEntry->type = type;
    newEntry->value = value;
    newEntry->next = symbolTable;
    symbolTable = newEntry;
}

SymbolValue getSymbolValue(char* name) {
    SymbolTableEntry* entry = symbolTable;
    SymbolValue default_val = {0}; // Default value if symbol not found

    while (entry != NULL) {
        if (strcmp(entry->name, name) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }

    fprintf(stderr, "Symbol '%s' not found\n", name);
    return default_val;
}

SymbolType getSymbolType(char* name) {
    SymbolTableEntry* entry = symbolTable;

    while (entry != NULL) {
        if (strcmp(entry->name, name) == 0) {
            return entry->type;
        }
        entry = entry->next;
    }

    fprintf(stderr, "Symbol '%s' not found\n", name);
    return -1; // Invalid type as a marker for symbol not found
}

void printSymbolTable() {
    printf("Symbol Table:\n");
    printf("%-20s %-10s %-10s\n", "Name", "Type", "Value");
    printf("----------------------------------------------\n");

    SymbolTableEntry* entry = symbolTable;
    while (entry != NULL) {
        printf("%-20s ", entry->name);
        switch (entry->type) {
            case TYPE_INTEGER:
                printf("%-10s ", "INTEGER");
                printf("%d\n", entry->value.int_val);
                break;
            case TYPE_REAL:
                printf("%-10s ", "REAL");
                printf("%lf\n", entry->value.real_val);
                break;
            case TYPE_CHAR:
                printf("%-10s ", "CHAR");
                printf("%c\n", entry->value.char_val);
                break;
            case TYPE_BOOLEAN:
                printf("%-10s ", "BOOLEAN");
                printf("%s\n", entry->value.bool_val ? "true" : "false");
                break;
            case TYPE_ARRAY:
                printf("%-10s ", "ARRAY");
                printf("NA\n");
                break;
            default:
                printf("Unknown type\n");
        }
        entry = entry->next;
    }
}

void freeSymbolTable() {
    SymbolTableEntry* entry = symbolTable;
    while (entry != NULL) {
        SymbolTableEntry* temp = entry;
        entry = entry->next;
        free(temp->name);
        free(temp);
    }
    symbolTable = NULL;
    freeArrayTable();
}

int isArrayPresent(char* name) {
    ArrayTableEntry* entry = arrayTable;
    while (entry != NULL) {
        if (strcmp(entry->arrayname, name) == 0) {
            return 1; // Array found
        }
        entry = entry->arraynext;
    }
    return 0; // Array not found
}


void insertArray(char* arrayname, SymbolType arraytype) {
    if (isArrayPresent(arrayname)) {
        // Array already present, return
        return;
    }

    // Array not found, create a new entry
    ArrayTableEntry* newEntry = (ArrayTableEntry*)malloc(sizeof(ArrayTableEntry));
    if (newEntry == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newEntry->arrayname = strdup(arrayname);
    newEntry->arraytype = arraytype;
    newEntry->arraynext = arrayTable;
    arrayTable = newEntry;
}

// Get type of array from array table
SymbolType getArrayType(char* name) {
    ArrayTableEntry* entry = arrayTable;

    while (entry != NULL) {
        if (strcmp(entry->arrayname, name) == 0) {
            return entry->arraytype;
        }
        entry = entry->arraynext;
    }

    fprintf(stderr, "Array '%s' not found\n", name);
    return -1; // Invalid type as a marker for array not found
}
void freeArrayTable() {
    ArrayTableEntry* entry = arrayTable;
    while (entry != NULL) {
        ArrayTableEntry* temp = entry;
        entry = entry->arraynext;
        free(temp->arrayname);
        free(temp);
    }
    arrayTable = NULL;
}