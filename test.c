#include <stdio.h>
#include "ft_printf.h"

int main(void) {
    int count;

    // %c: 文字
    count = ft_printf("Character test: %c\n", 'A');
    printf("Printed characters: %d\n", count);

    // %s: 文字列
    count = ft_printf("String test: %s\n", "Hello, world!");
    printf("Printed characters: %d\n", count);

    // %p: ポインタ
    int x = 42;
    count = ft_printf("Pointer test: %p\n", &x);
    printf("Printed characters: %d\n", count);

    // %d: 10進数整数
    count = ft_printf("Signed decimal test: %d\n", -12345);
    printf("Printed characters: %d\n", count);

    // %i: 整数
    count = ft_printf("Integer test: %i\n", 67890);
    printf("Printed characters: %d\n", count);

    // %u: 符号なし10進数
    count = ft_printf("Unsigned decimal test: %u\n", 4294967295U);
    printf("Printed characters: %d\n", count);

    // %x: 16進数（小文字）
    count = ft_printf("Hexadecimal lowercase test: %x\n", 255);
    printf("Printed characters: %d\n", count);

    // %X: 16進数（大文字）
    count = ft_printf("Hexadecimal uppercase test: %X\n", 255);
    printf("Printed characters: %d\n", count);

    // %%: パーセント記号
    count = ft_printf("Percent test: %%\n");
    printf("Printed characters: %d\n", count);

   	char *str = "fish";
	int num = 1;
	void *ptr = &num;
    char c = 'A';

    printf("Multiple specifiers: %c, %s, %d, %p, %%\n", c, str, num, ptr);
	ft_printf("Multiple specifiers: %c, %s, %d, %p, %%\n", c, str, num, ptr);
    return 0;
}

