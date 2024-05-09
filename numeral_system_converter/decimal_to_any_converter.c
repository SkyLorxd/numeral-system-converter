#include <stdio.h>

int alt_pow(int number, int target_pow) //Функция для возведения целого числа в целую полочижельную степень
{
    int result = 1;
m0:
    if (target_pow > 0)
    {
        target_pow--;
        result *= number;
        goto m0;
    }
    return result;
}

int main()
{
    printf("Enter number with base 10 and after space enter new base:\n");
    int num, new_base, digit;
    scanf("%d %d", &num, &new_base);
    int index_of_digit = 0;
m1: //Считаем степень последнего разряда чила в новой системе счисления
    if (alt_pow(new_base, index_of_digit + 1) <= num)
    {
        index_of_digit += 1;
        goto m1;
    }
m3:
    digit = 0;
m2: //Считаем цифру определённого разряда
    if ((digit + 1) * alt_pow(new_base, index_of_digit) <= num)
    {
        digit += 1;
        goto m2;
    }
    else
    {
        num -= digit * alt_pow(new_base, index_of_digit); //Уменьшаем исходное число на значение соответствующее цифре текущего разряда
        index_of_digit -= 1; //Уменьшаем переменную, содержащую текущий разряд, для подсчёта цифры в младшем разряде
        printf("%d ", digit);
        if (index_of_digit == -1) //Проверяем, являлся ли предыдущий разряд последним
        {
            return 0;
        }
        goto m3;
    }

    return 0;
}
