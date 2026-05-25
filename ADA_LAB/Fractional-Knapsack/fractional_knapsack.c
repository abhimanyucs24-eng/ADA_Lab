#include <stdio.h>

// Structure for an item
struct Item {
    int weight;
    int value;
    float ratio;
    int index;
};

// Sort items by value/weight ratio
void sortItems(struct Item items[], int n) {
    struct Item temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

// Fractional Knapsack
float fractionalKnapsack(struct Item items[], int n, int capacity) {

    float totalValue = 0.0;
    float x[n];   // stores fraction of each item

    // Initially no item is selected
    for (int i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    sortItems(items, n);

    for (int i = 0; i < n; i++) {

        // Take full item
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalValue += items[i].value;

            x[items[i].index - 1] = 1.0;
        }

        // Take fractional item
        else {
            x[items[i].index - 1] =
                (float)capacity / items[i].weight;

            totalValue += items[i].value *
                          x[items[i].index - 1];

            break;
        }
    }

    // Print solution set
    printf("\nSolution Set:\n{ ");
    for (int i = 0; i < n; i++) {
        printf("%.2f", x[i]);

        if (i != n - 1)
            printf(", ");
    }
    printf(" }\n");

    return totalValue;
}

int main() {

    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    // Input items
    for (int i = 0; i < n; i++) {

        printf("Enter value and weight of item %d: ",
               i + 1);

        scanf("%d %d",
              &items[i].value,
              &items[i].weight);

        items[i].ratio =
            (float)items[i].value / items[i].weight;

        items[i].index = i + 1;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    float maxValue =
        fractionalKnapsack(items, n, capacity);

    printf("\nMaximum value = %.2f\n", maxValue);

    return 0;
}