#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 10

struct HashMapEntry {
    char* key;
    int value;
    struct HashMapEntry *next;
};

struct HashMap {
    struct HashMapEntry **buckets;
    size_t size;
};

// Simple hash function
int hash(struct HashMap *m, char* key) {
    if (m->size == 0) {
        return 0;
    }

    int hash = 0;
    while (*key) {
        hash = (hash * 31 + *key);
        key++;
    }

    return hash % m->size;
}

void set(struct HashMap *m, char* key, int v) {
    int idx = hash(m, key);


    struct HashMapEntry *bucket = m->buckets[idx];
    while (bucket != NULL && strcmp(bucket->key, key)) {
        bucket = bucket->next;
    }

    if (bucket == NULL) {
        struct HashMapEntry *entry = malloc(sizeof(struct HashMapEntry));
        entry->key = key;
        entry->value = v;
        m->buckets[idx] = entry;
    } else {
        bucket->value = v;
    }
}

struct HashMapEntry* get(const struct HashMap *m, char* key) {
    int idx = hash((struct HashMap *) m, key);

    struct HashMapEntry *bucket = m->buckets[idx];

    while (bucket != NULL && strcmp(bucket->key, key)) {
        bucket = bucket->next;
    }

    return bucket;
}

void freeMap(struct HashMap *m) {
    for (int i = 0; i < m->size; i++) {
        struct HashMapEntry* bucket = m->buckets[i];

        while (bucket != NULL) {
            struct HashMapEntry *tmp = bucket;
            bucket = bucket->next;

            free(tmp);
        }
    }

    // Free the buckets array.
    free(m->buckets);
    // Lastly, free the hashmap pointer.
    free(m);
}

int main() {
    struct HashMap *map = malloc(sizeof(struct HashMap));
    if (map == NULL) {
        fprintf(stderr, "Could not allocate memory for map.");
        return EXIT_FAILURE;
    }

    map->buckets = calloc(SIZE, sizeof(struct HashMapEntry*));
    map->size = SIZE;

    struct HashMapEntry* item = get(map, "age");

    if (item == NULL) {
        puts("Key `age` does not exist.");
    }

    set(map, "age", 20);

    item = get(map, "age");

    if (item == NULL) {
        puts("Still doesn't exist");
    } else {
        printf("It exists. Value is: %d\n", item->value);
    }

    set(map, "age", 35);

    printf("Item is: %d", item->value);

    freeMap(map);
}
