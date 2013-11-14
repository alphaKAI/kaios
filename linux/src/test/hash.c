#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 3
#define KEYSIZE  256
#define VALSIZE  256

typedef struct _cell_t_ {
    char             key[KEYSIZE+1];
    char             value[VALSIZE+1];
    struct _cell_t_ *next;
} Cell;

typedef struct _table_t_ {
    Cell *table[HASHSIZE];
} HashTable;

/* hash api */
HashTable *hash_init_table();
int        hash_uninit_table(HashTable *ht);
int        hash_put(HashTable *ht, char *key, char *value);
char      *hash_get(HashTable *ht, char *key);
int        hash_delete(HashTable *ht, char *key);
void       print_table(HashTable *ht);

/* static */
static void  hash_free_cells(Cell *cell);
static int   hash_calc(char *key);
static Cell *hash_get_cell(HashTable *ht, char *key);


HashTable *hash_init_table()
{
    int        i;
    HashTable *ht;

    ht = (HashTable*)malloc(sizeof(HashTable));
    if (ht == NULL) {
        return NULL;
    }

    for (i=0; i<HASHSIZE; i++) {
        ht->table[i] = NULL;
    }

    return ht;
}

int hash_uninit_table(HashTable *ht)
{
    int i;
    for (i=0; i<HASHSIZE; i++) {
        hash_free_cells(ht->table[i]);
    }
    return 0;
}

int hash_put(HashTable *ht, char *key, char *value)
{
    int   hash_val;
    Cell *cell, *newcell;

    /* replace value if (key,value) pair already exists */
    cell = hash_get_cell(ht, key);
    if (cell) {
        strncpy(cell->value, value, VALSIZE);
    /*    printf("put item, key:%s, value:%s\n", cell->key, cell->value);*/
        return 0;
    }

    /* create new cell */
    newcell = (Cell*)malloc(sizeof(Cell));
    if (newcell == NULL) {
        return -1;
    }
    strncpy(newcell->key, key, KEYSIZE);
    strncpy(newcell->value, value, VALSIZE);
    newcell->next = NULL;

    hash_val = hash_calc(key);
    cell     = ht->table[hash_val];

    if (cell) {
        while (cell->next) cell = cell->next;
        cell->next              = newcell;
    } else {
        ht->table[hash_val]     = newcell;
    }

   /* printf("put item, key: %s, value: %s\n", newcell->key, newcell->value);*/
    return 0;
}

char *hash_get(HashTable *ht, char *key)
{
    Cell *cell;
    char *retval = NULL;
    
    cell = hash_get_cell(ht, key);
    if (cell) {
        retval = cell->value;
       /* printf("get value of hashtable(key: %s): value: %s\n", key, retval);*/
    } else {
       /* printf("get value of hashtable(key: %s): NOT FOUND\n", key);*/
    }
    
    return retval;
}

int hash_delete(HashTable *ht, char *key)
{
    int   hash_val;
    Cell *cell, *tmp;

    hash_val = hash_calc(key);
    cell     = ht->table[hash_val];
    tmp      = NULL;
    while (cell) {
        if (strncmp(cell->key, key, strlen(cell->key)) == 0) {
            if (tmp == NULL) {
                ht->table[hash_val] = cell->next;
            } else {
                tmp->next           = cell->next;
            }
         /*   printf("delete item, key: %s, value: %s\n", cell->key, cell->value);*/
            free(cell);
            return 0;
        }
        tmp  = cell;
        cell = cell->next;
    }
    return -1;                  /* not exists */
}

void print_table(HashTable *ht)
{
    int   i;
    Cell *cell;
    puts("=== table ===");
    for (i=0; i<HASHSIZE; i++) {
        printf("%d:\n", i);
        cell     = ht->table[i];
        while (cell) {
            printf("  key: %s, value: %s\n", cell->key, cell->value);
            cell = cell->next;
        }
    }
    puts("=============");
}

static void hash_free_cells(Cell *cell)
{
    if (cell == NULL) {
        return;
    }
    if (cell->next != NULL) {
        hash_free_cells(cell->next);
    }
    free(cell);
    return;
}

static int hash_calc(char *key)
{
    int hash_val       = 0;
    int c;
    while ((c = *key) != '\0') {
        hash_val      += (int)c;
        key++;
    }
    
    return (hash_val % HASHSIZE);
}

static Cell *hash_get_cell(HashTable *ht, char *key)
{
    int   hash_val;
    Cell *cell;

    hash_val                                            = hash_calc(key);
    cell                                                = ht->table[hash_val];
    while (cell) {
        if (strncmp(cell->key, key, strlen(cell->key)) == 0) {
            return cell;
        }
        cell = cell->next;
    }
    return NULL;
}

int main(int argc, char* argv[])
{
    HashTable *ht;
    char      *val;

    ht = hash_init_table();

    hash_put(ht, "apple", "red");
    hash_put(ht, "lemon", "yellow");
    hash_put(ht, "orange", "orange");
    
    print_table(ht);

    hash_put(ht, "orange", "green");

    print_table(ht);

    hash_delete(ht, "orange");

    print_table(ht);

    val = hash_get(ht, "apple");
    val = hash_get(ht, "lemon");
    val = hash_get(ht, "orange");

    hash_uninit_table(ht);
    return 0;
}


