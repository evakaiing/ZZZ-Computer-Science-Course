#include <stdio.h>
#include <stdint.h>


int32_t MaxSum(int32_t num) {
    int32_t max_sum = 0;
    int32_t current_sum = 0;

    int32_t first_digit = num % 10;
    num /= 10;
    int32_t second_digit = num % 10;
    num /= 10;

    while (num > 0) {
        int32_t third_digit = num % 10;

        current_sum = first_digit + second_digit + third_digit;
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }

        first_digit = second_digit;
        second_digit = third_digit;
        num /= 10;
    }

    return max_sum;
}

int Task() {
    int32_t num = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    int32_t max_sum = MaxSum(num);
    printf("Maximum sum of triplets: %d\n", max_sum);

    return 0;
}
