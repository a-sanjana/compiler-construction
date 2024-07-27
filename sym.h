#ifndef SYM_H
#define SYM_H

typedef enum {
    TYPE_INTEGER,
    TYPE_REAL,
    TYPE_CHAR,
    TYPE_BOOLEAN,
    TYPE_ARRAY
} SymbolType;

typedef union {
    int int_val;
    double real_val;
    char char_val;
    int bool_val; // 1 for true, 0 for false
} SymbolValue;

typedef struct SymbolTableEntry {
    char* name;
    SymbolType type;
    SymbolValue value;
    struct SymbolTableEntry* next;
} SymbolTableEntry;

typedef struct ArrayTableEntry {
    char* arrayname;       // Name of the array
    SymbolType arraytype;  // Type of the array
    struct ArrayTableEntry* arraynext; // Pointer to next array entry
} ArrayTableEntry;

void initSymbolTable();
void insertSymbol(char* name, SymbolType type, SymbolValue value);
int isSymbolPresent(char* name);
SymbolValue getSymbolValue(char* name);
SymbolType getSymbolType(char* name) ;
void printSymbolTable();
void freeSymbolTable();
int isArrayPresent(char* name);
void insertArray(char* arrayname, SymbolType arraytype);
SymbolType getArrayType(char* name);
void freeArrayTable();

#endif /* SYM_H */
