
#include <stdio.h>
#include <string.h>

int main() {
    char user[20], pass[20];

    printf("Username: ");
    scanf("%19s", user);

    printf("Password: ");
    scanf("%19s", pass);

    if (strcmp(user, "admin") == 0 &&
        strcmp(pass, "1234") == 0) {
        printf("Access Granted\n");
    } else {
        printf("Unauthorized Access\n");
    }

    printf("Security Audit Log:\n");
    printf("User: %s\n", user);
    printf("Access Attempt Recorded\n");

    return 0;
}
