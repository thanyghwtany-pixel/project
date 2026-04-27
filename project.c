#include <stdio.h>
#include <string.h>

#define BUFFER_CAPACITY 10 [cite: 22, 47]

typedef struct {
    char storage[BUFFER_CAPACITY];
    int head;  
    int tail;   
    int is_full; [cite: 48, 52]
} CircularBuffer;
void init_buffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->is_full = 0; [cite: 54, 57]
}
int check_full(CircularBuffer *cb) {
    return cb->is_full; [cite: 59]
}
int check_empty(CircularBuffer *cb) {
    return (!cb->is_full && (cb->head == cb->tail)); [cite: 61]
}
void enqueue_char(CircularBuffer *cb, char item) {
    if (check_full(cb)) {
        printf("\n[!] Buffer Overflow: Ignoring '%c'\n", item); [cite: 65, 66]
        return;
    }
    cb->storage[cb->head] = item;
    cb->head = (cb->head + 1) % BUFFER_CAPACITY;  [cite: 15, 64]

    if (cb->head == cb->tail) cb->is_full = 1; [cite: 17]
}

char dequeue_char(CircularBuffer *cb) {
    if (check_empty(cb)) {
        return '\0'; [cite: 70, 72]
    }
    char item = cb->storage[cb->tail];
    cb->is_full = 0; 
    cb->tail = (cb->tail + 1) % BUFFER_CAPACITY; [cite: 16, 69]
    return item;
}

int main() {
    CircularBuffer my_cb;
    init_buffer(&my_cb); [cite: 77, 78]

    char user_name[100];
    printf("Enter your full name: ");
    scanf("%s", user_name); [cite: 20, 80]
    strcat(user_name, "CE-ESY"); [cite: 20, 83]
    printf("Processing: %s\n", user_name);
    for (int i = 0; i < strlen(user_name); i++) {
        enqueue_char(&my_cb, user_name[i]); [cite: 85, 86]
    }
    printf("Buffer Output: ");
    while (!check_empty(&my_cb)) {
        printf("%c", dequeue_char(&my_cb)); [cite: 88, 91]
    }
    
    printf("\nStatus: Buffer is empty now.\n"); [cite: 21]
    return 0;
}
