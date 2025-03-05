#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 10000  // 假设最大支持10000位数

// 定义大数类型
typedef struct {
    int digits[MAX_DIGITS];  // 存储大数的数组，逆序存储
    int length;  // 大数的长度
} BigInt;

// 初始化大数为0
void initBigInt(BigInt *num) {
    memset(num->digits, 0, sizeof(num->digits));
    num->length = 0;
}

// 将字符串转换为大数
void strToBigInt(const char *str, BigInt *num) {
    int len = strlen(str);
    num->length = len;
    for (int i = 0; i < len; i++) {
        num->digits[i] = str[len - 1 - i] - '0';
    }
}

// 输出大数
void printBigInt(const BigInt *num) {
    for (int i = num->length - 1; i >= 0; i--) {
        printf("%d", num->digits[i]);
    }
    printf("\n");
}

// 大数加法
void addBigInt(const BigInt *a, const BigInt *b, BigInt *result) {
    int carry = 0;
    int maxLength = a->length > b->length ? a->length : b->length;
    result->length = maxLength;
    for (int i = 0; i < maxLength || carry; i++) {
        int sum = a->digits[i] + b->digits[i] + carry;
        result->digits[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry) {
        result->digits[result->length++] = carry;
    }
}

// 大数减法 (假设 a >= b)
void subtractBigInt(const BigInt *a, const BigInt *b, BigInt *result) {
    int borrow = 0;
    for (int i = 0; i < a->length; i++) {
        int diff = a->digits[i] - b->digits[i] - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result->digits[i] = diff;
    }
    // 结果的长度
    result->length = a->length;
    while (result->length > 1 && result->digits[result->length - 1] == 0) {
        result->length--;
    }
}

// 大数乘法
void multiplyBigInt(const BigInt *a, const BigInt *b, BigInt *result) {
    memset(result->digits, 0, sizeof(result->digits));
    result->length = a->length + b->length;
    for (int i = 0; i < a->length; i++) {
        for (int j = 0; j < b->length; j++) {
            result->digits[i + j] += a->digits[i] * b->digits[j];
            result->digits[i + j + 1] += result->digits[i + j] / 10;
            result->digits[i + j] %= 10;
        }
    }
    while (result->length > 1 && result->digits[result->length - 1] == 0) {
        result->length--;
    }
}

// 大数除法 (a / b, 返回商和余数)
void divideBigInt(const BigInt *a, const BigInt *b, BigInt *quotient, BigInt *remainder) {
    initBigInt(quotient);
    initBigInt(remainder);
    
    for (int i = a->length - 1; i >= 0; i--) {
        // 向商添加一位
        for (int j = quotient->length - 1; j > 0; j--) {
            quotient->digits[j] = quotient->digits[j - 1];
        }
        quotient->digits[0] = a->digits[i];
        quotient->length++;
        
        // 在商上进行除法
        int q = 0;
        while (compareBigInt(quotient, b) >= 0) {
            subtractBigInt(quotient, b, quotient);
            q++;
        }
        quotient->digits[0] = q;
    }
    
    // 余数
    for (int i = 0; i < b->length; i++) {
        remainder->digits[i] = a->digits[i];
    }
    remainder->length = b->length;
}

// 大数比较 (返回a - b的结果: > 0 返回1, == 0 返回0, < 0 返回-1)
int compareBigInt(const BigInt *a, const BigInt *b) {
    if (a->length > b->length) return 1;
    if (a->length < b->length) return -1;
    for (int i = a->length - 1; i >= 0; i--) {
        if (a->digits[i] > b->digits[i]) return 1;
        if (a->digits[i] < b->digits[i]) return -1;
    }
    return 0;
}

int main() {
    BigInt a, b, result;
    initBigInt(&a);
    initBigInt(&b);
    initBigInt(&result);
    
    char strA[10000], strB[10000];
    scanf("%s %s", strA, strB);
    
    strToBigInt(strA, &a);
    strToBigInt(strB, &b);
    
    addBigInt(&a, &b, &result);
    printf("Addition: ");
    printBigInt(&result);
    
    subtractBigInt(&a, &b, &result);
    printf("Subtraction: ");
    printBigInt(&result);
    
    multiplyBigInt(&a, &b, &result);
    printf("Multiplication: ");
    printBigInt(&result);
    
    divideBigInt(&a, &b, &result, &result);
    printf("Division: ");
    printBigInt(&result);
    
    return 0;
}