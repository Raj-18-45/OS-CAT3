
#include <stdio.h>

int main() {
    int p[] = {2,3,2,1,5,2,4,5,3,2,1};
    int f[3] = {-1,-1,-1};
    int faults = 0, hits = 0, pos = 0;

    for (int i = 0; i < 11; i++) {
        int found = 0;

        for (int j = 0; j < 3; j++)
            if (f[j] == p[i])
                found = 1;

        if (found) {
            hits++;
        } else {
            f[pos] = p[i];
            pos = (pos + 1) % 3;
            faults++;
        }

        printf("%d\t%d %d %d\n", p[i], f[0], f[1], f[2]);
    }

    printf("Page Hits = %d\n", hits);
    printf("Page Faults = %d\n", faults);

    return 0;
}
