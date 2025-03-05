#include <stdio.h>

#define MAX_INPUT 2505 * 25 

int main() {
    char input[MAX_INPUT]; 
    int len = 0;           
    char ch;

    while (scanf("%c", &ch) != EOF) {
        if (ch == 'E') {
            break; 
        }
        input[len++] = ch;
    }


    int W11 = 0, L11 = 0;
    for (int i = 0; i < len; i++) {
        if (input[i] == 'W') W11++;
        if (input[i] == 'L') L11++;


        if ((W11 >= 11 && W11 - L11 >= 2) || (L11 >= 11 && L11 - W11 >= 2)) {
            printf("%d:%d\n", W11, L11);
            W11 = 0;
            L11 = 0;
        }
    }

    if (W11 > 0 || L11 > 0) {
        printf("%d:%d\n", W11, L11);
    }

    printf("\n"); 


    int W21 = 0, L21 = 0;
    for (int i = 0; i < len; i++) {
        if (input[i] == 'W') W21++;
        if (input[i] == 'L') L21++;

    
        if ((W21 >= 21 && W21 - L21 >= 2) || (L21 >= 21 && L21 - W21 >= 2)) {
            printf("%d:%d\n", W21, L21);
            W21 = 0;
            L21 = 0;
        }
    }
    // 处理未完成的最后一局
    if (W21 > 0 || L21 > 0) {
        printf("%d:%d\n", W21, L21);
    }

    return 0;
}