/*
 * Experiment 28: Simulate the UNIX 'grep' command.
 * Usage: ./exp28 <pattern> <filename>
 * Compile: gcc 28_simulate_grep_command.c -o exp28
 * Run:     ./exp28 error logfile.txt
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <pattern> <filename>\n", argv[0]);
        exit(1);
    }

    char *pattern = argv[1];
    FILE *fp = fopen(argv[2], "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    char line[1024];
    int lineNo = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        lineNo++;
        if (strstr(line, pattern) != NULL)
            printf("%d: %s", lineNo, line);
    }

    fclose(fp);
    return 0;
}
