
#include <stdio.h>

int main() {
    int b[] = {200, 300, 400, 250};
    int p[] = {100, 250, 150, 300, 120};
    char *alg[] = {"First Fit", "Best Fit", "Worst Fit"};

    for (int a = 0; a < 3; a++) {
        int temp[4], used = 0;

        for (int j = 0; j < 4; j++)
            temp[j] = b[j];

        printf("\n%s\n", alg[a]);

        for (int i = 0; i < 5; i++) {
            int k = -1;

            for (int j = 0; j < 4; j++) {
                if (temp[j] >= p[i] &&
                   (k == -1 ||
                   (a == 1 && temp[j] < temp[k]) ||
                   (a == 2 && temp[j] > temp[k])))
                    k = j;

                if (a == 0 && k != -1) break;
            }

            if (k != -1) {
                printf("P%d -> B%d\n", i + 1, k + 1);
                temp[k] -= p[i];
                used += p[i];
            } else {
                printf("P%d -> Not Allocated\n", i + 1);
            }
        }

        printf("Utilization = %.2f%%\n",
               used * 100.0 / 1150);
    }

    printf("\nSwapping: Process moved from RAM to Disk.\n");

    return 0;
}
