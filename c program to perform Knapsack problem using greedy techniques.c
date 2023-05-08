#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
} Item;

int compareItems(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;

    double ratioA = (double)itemA->value / (double)itemA->weight;
    double ratioB = (double)itemB->value / (double)itemB->weight;

    if (ratioA > ratioB) {
        return -1;
    } else if (ratioA < ratioB) {
        return 1;
    } else {
        return 0;
    }
}

int knapsack(Item items[], int numItems, int capacity) {
    qsort(items, numItems, sizeof(Item), compareItems);

    int weight = 0;
    int value = 0;

    for (int i = 0; i < numItems; i++) {
        if (weight + items[i].weight <= capacity) {
            weight += items[i].weight;
            value += items[i].value;
        } else {
            int remainingCapacity = capacity - weight;
            value += remainingCapacity * ((double)items[i].value / (double)items[i].weight);
            break;
        }
    }

    return value;
}

int main() {
    Item items[] = {
        { 60, 10 },
        { 100, 20 },
        { 120, 30 }
    };
    int capacity = 50;
    int numItems = sizeof(items) / sizeof(Item);

    int maxValue = knapsack(items, numItems, capacity);

    printf("Maximum value that can be put in a knapsack of capacity %d: %d\n", capacity, maxValue);

    return 0;
}
