#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void check_res(int meu, int real)
{
    printf("   [Retorno] ft_printf: %d | printf: %d -> ", meu, real);
    if (meu == real)
        printf("\033[0;32m[OK]\033[0m\n\n");
    else
        printf("\033[0;31m[KO]\033[0m ❌\n\n");
}

int main(void)
{
    int meu;
    int real;
    char *null_str = NULL;
    void *null_ptr = NULL;

    printf("\033[1;35m--- INICIANDO TESTES DO SEU MAIN ---\033[0m\n\n");

    printf("1. Testando %%%%\n");
    meu = ft_printf("%%\n");
    real = printf("%%\n");
    check_res(meu, real);

    printf("2. Testando INT_MIN com %%i\n");
    meu = ft_printf("%i\n", INT_MIN);
    real = printf("%i\n", INT_MIN);
    check_res(meu, real);

    printf("3. Testando INT_MIN com %%d\n");
    meu = ft_printf("%d\n", INT_MIN);
    real = printf("%d\n", INT_MIN);
    check_res(meu, real);

    printf("4. Testando %%p com NULL\n");
    meu = ft_printf("%p\n", null_ptr);
    real = printf("%p\n", null_ptr);
    check_res(meu, real);

    printf("5. Testando %%u com -2\n");
    meu = ft_printf("%u\n", -2);
    real = printf("%u\n", -2);
    check_res(meu, real);

    printf("6. Testando multiplos chars\n");
    meu = ft_printf("\nchar: %c %c %c\n", 'a', 'b', 'c');
    real = printf("\nchar: %c %c %c\n", 'a', 'b', 'c');
    check_res(meu, real);

    printf("7. Testando Strings (hello e vazia)\n");
    meu = ft_printf("Strings: %s %s\n", "hello", "");
    real = printf("Strings: %s %s\n", "hello", "");
    check_res(meu, real);

    printf("8. Testando Strings (hello e world)\n");
    meu = ft_printf("Strings: %s %s\n", "hello", "world");
    real = printf("Strings: %s %s\n", "hello", "world");
    check_res(meu, real);

    printf("9. Testando especificador desconhecido (%%a)\n");
    meu = ft_printf("Hello %a World\n", "my awsome 42");
    printf("   *(Nota: O comportamento de %%a no ft_printf depende da sua implementacao)\n");
    printf("   [Retorno] ft_printf: %d\n\n", meu);

    printf("10. Testando inteiros mistos\n");
    meu = ft_printf("int decimal: %d %d\n", 0, INT_MIN);
    real = printf("int decimal: %d %d\n", 0, INT_MIN);
    check_res(meu, real);

    printf("11. Testando sequencia longa de inteiros\n");
    meu = ft_printf("int decimal: %d%d%d%d %d%d%d\n", 2, 3, 4, 5, 6, 7, 8);
    real = printf("int decimal: %d%d%d%d %d%d%d\n", 2, 3, 4, 5, 6, 7, 8);
    check_res(meu, real);

    printf("12. Testando %%i simples\n");
    meu = ft_printf("int: %i %i\n", 2, 3);
    real = printf("int: %i %i\n", 2, 3);
    check_res(meu, real);

    printf("13. Testando unsigned int com overflow (-1)\n");
    meu = ft_printf("unsigned int: %u %u\n", -1, 3);
    real = printf("unsigned int: %u %u\n", -1, 3);
    check_res(meu, real);

    printf("14. Testando hexadecimal minusculo (%%x)\n");
    meu = ft_printf("hexadecimal x: %x %x\n", 16, 255);
    real = printf("hexadecimal x: %x %x\n", 16, 255);
    check_res(meu, real);

    printf("15. Testando hexadecimal maiusculo (%%X)\n");
    meu = ft_printf("hexadecimal X: %X %X\n", 16, 255);
    real = printf("hexadecimal X: %X %X\n", 16, 255);
    check_res(meu, real);

    printf("16. Testando ponteiros (NULL e String)\n");
    meu = ft_printf("pointer: %p %p\n", null_ptr, "World");
    real = printf("pointer: %p %p\n", null_ptr, "World");
    check_res(meu, real);

    printf("17. Testando texto estatico com %%%%\n");
    meu = ft_printf("percent: %%\n");
    real = printf("percent: %%\n");
    check_res(meu, real);

    printf("18. Testando print aninhado (ft_printf dentro de outro)\n");
    meu = ft_printf("%i %s\n", ft_printf("Hello"), "string");
    printf("\n");
    real = printf("%i %s\n", printf("Hello"), "string");
    printf("\n");
    check_res(meu, real);

    printf("\n\033[1;33m--- FINAL EDGE CASES ---\033[0m\n\n");

    printf("19. Cast explicito de INT_MIN\n");
    meu = ft_printf("%d\n", (int)-2147483648);
    real = printf("%d\n", (int)-2147483648);
    check_res(meu, real);

    printf("20. String nula (%%s com NULL)\n");
    meu = ft_printf("%s\n", null_str);
    real = printf("%s\n", null_str);
    check_res(meu, real);

    printf("21. Validacao de variaveis de retorno R e S\n");
    int r = ft_printf("%%\n");
    int s = printf("%%\n");
    printf("ft_printf retornou (r): %d\nprintf retornou (s): %d\n", r, s);
    if (r == s)
        printf("\033[0;32m[OK]\033[0m\n\n");
    else
        printf("\033[0;31m[KO]\033[0m\n\n");

    printf("22. Maior Unsigned Int possivel\n");
    meu = ft_printf("%u\n", 4294967295U);
    real = printf("%u\n", 4294967295U);
    check_res(meu, real);

    printf("23. Ponteiro NULL isolado\n");
    meu = ft_printf("%p\n", null_ptr);
    real = printf("%p\n", null_ptr);
    check_res(meu, real);

    printf("\033[1;35m--- FIM DOS TESTES ---\033[0m\n");
    return (0);
}