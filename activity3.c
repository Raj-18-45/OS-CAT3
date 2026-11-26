
#include <stdio.h>

int main() {
    int p[] = {1,2,3,4,1,2,5,1,2,3,4,5};
    int n = 12;

    for (int alg = 0; alg < 4; alg++) {
        for (int k = 3; k <= 4; k++) {
            int f[4] = {-1,-1,-1,-1}, t[4] = {0};
            int bit[4] = {0}, ptr = 0, hit = 0, fault = 0;

            for (int i = 0; i < n; i++) {
                int j, found = 0;

                for (j = 0; j < k; j++)
                    if (f[j] == p[i]) {
                        found = 1;
                        break;
                    }

                if (found) {
                    hit++;
                    t[j] = i;
                    bit[j] = 1;
                } else {
                    fault++;
                    for (j = 0; j < k && f[j] != -1; j++);

                    if (j == k) {
                        if (alg == 0) j = ptr;
                        else if (alg == 1) {
                            j = 0;
                            for (int x = 1; x < k; x++)
                                if (t[x] < t[j]) j = x;
                        }
                        else if (alg == 2) {
                            int far = -1;
                            j = 0;
                            for (int x = 0; x < k; x++) {
                                int y;
                                for (y = i + 1; y < n; y++)
                                    if (p[y] == f[x]) break;
                                if (y > far) far = y, j = x;
                            }
                        }
                        else {
                            while (bit[ptr]) {
                                bit[ptr] = 0;
                                ptr = (ptr + 1) % k;
                            }
                            j = ptr;
                            ptr = (ptr + 1) % k;
                        }
                    }

                    f[j] = p[i];
                    t[j] = i;
                    bit[j] = 1;
                    if (alg == 0) ptr = (ptr + 1) % k;
                }
            }

            printf("\nAlgorithm %d, Frames %d", alg + 1, k);
            printf("\nFaults = %d, Hits = %d\n", fault, hit);
        }
    }
    return 0;
}
