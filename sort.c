//
//  sort.c
//  WordCount
//
//  Created by Антон Чемодуров on 10.09.2021.
//
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("cannot open file\n");
        return 0;
    }
    
    char num[100];
    int c, i = 0;
    while ((c = fgetc(file)) != '\n') {
        num[i++] = (char)c;
    }
    num[i] = 0;
    int n = atoi(num);
    
    float *nums = (float *)malloc(n * sizeof(float));
    if (nums == NULL) {
        perror("error");
        return 0;
    }
    
    i = 0;
    int j = 0;
    while ((c = fgetc(file)) != EOF) {
        if (c == ' ') {
            num[i] = 0;
            nums[j++] = atof(num);
            i = 0;
        } else {
            num[i++] = (char)c;
        }
    }
    num[i] = 0;
    nums[j++] = atof(num);
    
    for (int i = 0; i < n; i++) {
        printf("%f ", nums[i]);
    }
    
    free(nums);
}
