#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Corrected this line

#define INITIAL_CAPACITY 10
#define LOAD_FACTOR 0.7

typedef struct node {
    int key;
    int value;
    struct node* next;
} Node;

typedef struct {
    Node** buckets;
    int capacity;
    int size;
} HashMap;

// Forward declaration for resizeHashMap
void resizeHashMap(HashMap* map);

unsigned int hash(int key, int capacity) {
    return abs(key) % capacity;
}

HashMap* createHashMap() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->capacity = INITIAL_CAPACITY;
    map->size = 0;
    map->buckets = (Node**)calloc(map->capacity, sizeof(Node*));
    return map;
}

void put(HashMap* map, int key, int value) {
    // Check if resizing is needed
    if ((double)map->size / map->capacity >= LOAD_FACTOR) {
        resizeHashMap(map);
    }

    unsigned int index = hash(key, map->capacity);
    Node* current = map->buckets[index];

    // Search for the key to update it if it exists
    while (current) {
        if (current->key == key) {
            current->value = value;
            return;
        }
        current = current->next;
    }

    // If key not found, create a new node and insert it
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
    map->size++;
}

int get(HashMap* map, int key) {
    unsigned int index = hash(key, map->capacity);
    Node* current = map->buckets[index];
    while (current) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Key not found
}

void removeKey(HashMap* map, int key) {
    unsigned int index = hash(key, map->capacity);
    Node* current = map->buckets[index];
    Node* prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            // Unlink the node from the list
            if (prev == NULL) { // It's the head of the list
                map->buckets[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            map->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void resizeHashMap(HashMap* map) {
    int oldCapacity = map->capacity;
    Node** oldBuckets = map->buckets;

    // Double the capacity and create a new bucket array
    map->capacity *= 2;
    map->buckets = (Node**)calloc(map->capacity, sizeof(Node*));
    
    // Rehash and move all nodes to the new buckets
    for (int i = 0; i < oldCapacity; i++) {
        Node* current = oldBuckets[i];
        while (current != NULL) {
            Node* next = current->next;
            
            unsigned int newIndex = hash(current->key, map->capacity);
            current->next = map->buckets[newIndex];
            map->buckets[newIndex] = current;
            
            current = next;
        }
    }
    free(oldBuckets);
}

void freeHashMap(HashMap* map) {
    for (int i = 0; i < map->capacity; i++) {
        Node* node = map->buckets[i];
        while (node) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}

int main() {
    int N;
    scanf("%d", &N);
    HashMap* map = createHashMap();
    for (int i = 0; i < N; i++) {
        char operation[10];
        int key, value;
        scanf("%s", operation);
        if (strcmp(operation, "put") == 0) {
            scanf("%d %d", &key, &value);
            put(map, key, value);
        } else if (strcmp(operation, "get") == 0) {
            scanf("%d", &key);
            printf("%d\n", get(map, key));
        } else if (strcmp(operation, "remove") == 0) {
            scanf("%d", &key);
            removeKey(map, key);
        }
    }
    freeHashMap(map);
    return 0;
}