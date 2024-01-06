#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

typedef int32_t** Matrix;

int Task() {
    FILE* file;
    const char* path = "../tasks/matrix/tasks/6/matrix.txt"
    file = fopen(path, "r");
    int count = 1;
    int32_t* massive = (int32_t*)malloc(sizeof(int32_t) * 64);
    int k = 0;
    while (count > 0) {
        count = fscanf(file, "%d", &massive[k]);
        ++k;
    }
    int len = 0;
    len = (int)sqrt(k);
    Matrix matrix = (Matrix)malloc(sizeof(int32_t*) * len);
    for (int i = 0; i < len; ++i) {
        matrix[i] = (int32_t*)malloc(sizeof(int32_t) * len);
    }
    k = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            matrix[i][j] = massive[k];
            ++k;
        }
    }
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    int32_t Min = matrix[0][0];
    int32_t numbers[len];
    for (int i = 0; i < len; ++i) {
        numbers[i] = 0;
    }
    int last = 0;
    for (int j = 0; j < len; ++j) {
        for (int i = 0; i < len; ++i) {
            if (matrix[i][j] < Min) {
                Min = matrix[i][j];
                for (int h = 0; h < j; ++h) {
                    numbers[h] = 0;
                }
                numbers[j] = 1;
                last = j;
            } else if (matrix[i][j] == Min) {
                numbers[j] = 1;
                last = j;
            }
        }
    }
    for (int j = 0; j < len; ++j) {
        if (numbers[j] == 1) {
            for (int i = 0; i < len; ++i) {
                if (j != last) {
                    matrix[i][last] += matrix[i][j];
                }
            }
        }
    }
    printf("\n");
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    fclose(file);
    free(massive);
    for (int i = 0; i < len; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}
