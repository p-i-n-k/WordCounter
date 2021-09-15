//
//  main.c
//  WordCount
//
//  Created by Антон Чемодуров on 09.09.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "WordCounter.h"


int main(int argc, const char * argv[]) {
    if (argc < 2) {
        perror("Enter file name");
        exit(0);
    }
    FILE *file_ = fopen(argv[1], "r");
    if (file_ == NULL) {
        perror("file doesn't exist");
    }
    file_info info = get_file_info(file_);
    
    printf("\t%d %d %d %s\n", info.lines_num, info.words_num, info.size, argv[1]);
    
    
    
}


