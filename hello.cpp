#include <iostream>
 
int main() {
    // 外层循环控制行
    for (int i = 1; i <= 9; i++) {
        // 内层循环控制列
        for (int j = 1; j <= i; j++) {
            // 打印乘法表的一项，例如：1x1=1, 1x2=2, ..., 2x1=2, 2x2=4, ...
            std::cout << j << "x" << i << "=" << (i * j) << "\t"; // \t用于制表符对齐
        }
        // 每完成一行打印一个换行符
        std::cout << std::endl;
    }
    return 0;
}
