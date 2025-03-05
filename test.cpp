#include <iostream>
 
int sum(int a, int b) {
    return a + b;
}
 
int main() {
    int result = sum(5, 10);
    std::cout << "The sum is: " << result << std::endl;
    return 0;
}
