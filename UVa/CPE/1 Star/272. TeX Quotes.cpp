#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int n = 0;
    char str[1000];
    while (fgets(str, 1000, stdin)) {
        str[strlen(str) - 1] = '\0';
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == '"') {
                if (n % 2 == 0) printf("``");
                else printf("''");
                n++;
            } else printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}