/*************************************************************************
	> File Name: Hash.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月28日 星期六 15时56分48秒
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

typedef struct Data {
    char *str;
    struct Data *next;
}Data;


typedef struct HashTable {
    Data *data;
    int size;
    int (*func)(const char *str);
    int cnt;
} HashTable;


void insert(HashTable *h, const char *str);
void clear(HashTable *h);
int APHash(const char *str);
HashTable *init(int size, int (*func)(const char *str));

int APHash(const char *str) {
    int hash = 0;

    for (int i = 0; str[i]; i++) {
        if(i & 1) {
            hash  ^= (hash << 7) ^ str[i] ^ (hash >> 5);
        }else {
            hash ^= (~((hash << 11) ^ str[i] ^ (hash >> 5)));
        }
    }
    
    return hash & 0x7fffffff;
    
}

int BKDRHash(const char *str) {
    int hash = 0, seed = 131;
    for(int i = 0; str[i]; i++) {
        hash = hash * seed + str[i];
    }
    return hash & 0x7fffffff;
}


int zobrist_table[50][256] = {0};

void init_zobrist_table() {
    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 256; j++) {
            zobrist_table[i][j] = rand();
        }
    }
    return ;
}




HashTable *init(int size, int (*func)(const char *str)) {
    HashTable *p = (HashTable *)malloc(sizeof(HashTable));
    p->data = (Data *)calloc(sizeof(Data) , size);
    p->size = size;
    p->func = func;
    p->cnt = 0;
    return p;
}

void clear(HashTable *h) {
    if(h == NULL) return ;
    free(h->data);
    free(h);
    return ;
}

int query(HashTable *h, const char *str) {
    int ind = h->func(str) % h->size;
    Data *p = h->data[ind].next;
    while(p) {
        if(strcmp(p->str, str) == 0) return -1;
        p = p->next;
        h->cnt += 1;
    }
    return ind;
}

void insert(HashTable *h, const char *str){
    int ind = query(h, str);
    if(ind == -1) return ;
    Data *data = (Data *)malloc(sizeof(Data));
    data->str = strdup(str);
    data->next = NULL;
    data->next = h->data[ind].next;
    h->data[ind].next = data;
    return ;
}

int zobristHash(const char *str) {
    static int flag = 1;
    if(flag) {
        flag = 0;
        init_zobrist_table();
    }
    int hash = 0;
    for(int i = 0; str[i]; i++) {
        hash ^= zobrist_table[i][str[i]];
    }
    return hash &0x7fffffff;
}


int main() {
   /* srand(time(0));
    char str1[50] = {0}, str2[50] = {0};
    for(int i = 0; i < 16; i++) {
        str1[i] = (i & 1) ? 'a' :'b';
    }
    for(int i = 0; i < 32; i++) {
        str2[i] = (i & 2) ? 'a' :'b';
    }
    printf("BKDRHash(%s) = %d\n",str1, BKDRHash(str1));
    printf("BKDRHash(%s) = %d\n",str2, BKDRHash(str2));
    printf("APHash(%s) = %d\n",str1, APHash(str1));
    printf("APHash(%s) = %d\n",str1, APHash(str2));
    printf("zobristHash(%s) = %d\n", str1, zobristHash(str1));
    printf("zobristHash(%s) = %d\n", str2, zobristHash(str2));*/

    HashTable *apHashTable = init(100, APHash); 
    HashTable *bkdrHashTable = init(100, BKDRHash);
    HashTable *zobristHashTable = init(100, zobristHash);

    for(int i = 0; i < 10000; i++) {
        char str[7] = {0};
        for(int j = 0; j < 6; j++) {
            str[j] = rand() % 26 + 'a';
        }
        str[6] = 0;
        insert(apHashTable, str);
        insert(bkdrHashTable, str);
        insert(zobristHashTable, str);
    }
    printf("APHash(%d) = %d\n", 10000, apHashTable->cnt);
    printf("bkdeHash(%d) = %d\n", 10000, bkdrHashTable->cnt);
    printf("zobristHash(%d) = %d\n", 10000, zobristHashTable->cnt);
    
    return 0;
}
