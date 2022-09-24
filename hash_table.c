#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX_NAME 256
#define TABEL_SIZE 10


typedef struct{
    char name[MAX_NAME];
    int age;
}Node;

Node *hash_table[TABEL_SIZE];

unsigned int hash(char *name){
    int length = strnlen(name,MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++){
        hash_value += name[i];
        hash_value =  (hash_value * name[i]) % TABEL_SIZE;
    }
    return hash_value;
}

void init_hash_table(){
    for (int i = 0; i < TABEL_SIZE; i++){
        hash_table[i] = NULL;
    }
    // table is empty
}

void print_table(){
    printf("START\n");
    for (int i = 0; i < TABEL_SIZE; i++){
        if (hash_table[i] == NULL){
            printf("\t%i\t---\n",i);
        }else{
            printf("\t%i\t%s\n",i, hash_table[i]->name);
        }
    }
    printf("END\n");
}

bool hash_table_insert(Node *p){
    if (p == NULL) return false;
    int index = hash(p->name);
    for (int i = 0; i < TABEL_SIZE; i++){
        int try = (i + index) % TABEL_SIZE;
        if (hash_table[try] == NULL){
            hash_table[try] = p;
            return true; 
        }
    }
    return false;
}

// find a person in the table by thier name
Node *hash_table_lookup(char *name){
    int index = hash(name);
    for (int i = 0; i < TABEL_SIZE; i++){
        int try = (i + index) % TABEL_SIZE;
        if (hash_table[try] != NULL && strncmp(hash_table[try]->name, name, TABEL_SIZE) == 0){
            return hash_table[try];
        }
    }
    return NULL;
}

Node *hash_table_delete(char *name){
    int index = hash(name);
    for (int i = 0; i < TABEL_SIZE; i++){
        int try = (i + index) % TABEL_SIZE;
        if (hash_table[try] != NULL && strncmp(hash_table[try]->name, name, TABEL_SIZE) == 0){
            Node *tmp = hash_table[try];
            hash_table[try] = NULL;
            return hash_table[try];
        }
    }
    return NULL;
}

int main(){

    init_hash_table();

    Node amal = {.name = "amal" , .age = 27};
    Node nimal = {.name = "nimal" , .age = 34};
    Node kamal = {.name = "kamal" , .age = 55};
    Node foo = {.name = "foo", .age = 33};

    hash_table_insert(&amal);
    hash_table_insert(&nimal);
    hash_table_insert(&kamal);
    hash_table_insert(&foo);

    print_table();

    Node *tmp = hash_table_lookup("foo");
    if (tmp == NULL){
        printf("Not Found\n");
    }else{
        printf("Found: %s\n",tmp->name);
    }

    tmp = hash_table_lookup("bar");
    if (tmp == NULL){
        printf("Not Found\n");
    }else{
        printf("Found: %s\n",tmp->name);
    }

    hash_table_delete("foo");
    tmp = hash_table_lookup("foo");
    if (tmp == NULL){
        printf("Not Found\n");
    }else{
        printf("Found: %s\n",tmp->name);
    }

    print_table();

    return 0;
}