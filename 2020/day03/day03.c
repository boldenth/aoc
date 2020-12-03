// day03.c
// Thomas Bolden

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int count_trees(char **board, int width, int height, int right, int down) {
    int num_trees = 0;

    int x = 0, y = 0;
    for (int i = 0; i < height - 1; i++) {
        x = (x + right) % (width - 1);
        y += down;

        if (y >= height) break;

        if (board[y][x] == '#') {
            num_trees++;
        }
    }

    return num_trees;
}

int main(void) {
    FILE *file = fopen("input.txt", "r");

    char line[0x100];

    char **board = NULL;

    int lines = 0, length = 0;
    while (fgets(line, sizeof(line), file)) {
        board = realloc(board, (lines + 1) * sizeof(char *));
        
        int len = strlen(line);
        if (len > length) length = len;

        *(board + lines) = calloc(sizeof(char), length + 1);
        strncpy(*(board + lines), line, length);
        
        lines++;
    }

    int trees_11 = count_trees(board, length, lines, 1, 1);
    int trees_31 = count_trees(board, length, lines, 3, 1);
    int trees_51 = count_trees(board, length, lines, 5, 1);
    int trees_71 = count_trees(board, length, lines, 7, 1);
    int trees_12 = count_trees(board, length, lines, 1, 2);

    printf("3 right 1 down: %d\n", trees_31);
    printf("product of all: %d\n", trees_11 * trees_31 * trees_51 * trees_71 * trees_12);

    fclose(file);

    for (char **curr = board; *curr; curr++) free(*curr);
    free(board);

    return 0;
}


