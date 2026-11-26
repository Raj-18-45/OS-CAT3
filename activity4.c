
#include <stdio.h>
#include <string.h>

int main() {
    char file[5][20] = {"Design.docx", "Report.pdf"};
    int count = 2, lock = 0, choice;

    while (1) {
        printf("\n1.Create 2.Read 3.Write 4.Delete 5.Lock 6.Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            scanf("%19s", file[count++]);
            printf("File Created\n");
        }
        else if (choice == 2) {
            for (int i = 0; i < count; i++)
                printf("%s\n", file[i]);
        }
        else if (choice == 3) {
            if (lock)
                printf("File Locked\n");
            else
                printf("File Updated\n");
        }
        else if (choice == 4) {
            count--;
            printf("File Deleted\n");
        }
        else if (choice == 5) {
            lock = !lock;
            printf(lock ? "File Locked\n" : "File Unlocked\n");
        }
        else break;
    }
    return 0;
}
