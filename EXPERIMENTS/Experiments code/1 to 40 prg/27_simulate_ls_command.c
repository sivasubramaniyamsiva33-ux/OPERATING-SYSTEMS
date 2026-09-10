/*
 * Experiment 27: Simulate the function of the UNIX 'ls' command.
 * Usage: ./exp27 [-l] [directory]
 * Compile: gcc 27_simulate_ls_command.c -o exp27
 * Run:     ./exp27 -l /some/dir
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

void printPermissions(mode_t mode) {
    printf((S_ISDIR(mode)) ? "d" : "-");
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
}

int main(int argc, char *argv[]) {
    char *path = ".";
    int longFormat = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-l") == 0)
            longFormat = 1;
        else
            path = argv[i];
    }

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.')
            continue;

        if (longFormat) {
            char fullPath[512];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
            struct stat st;
            if (stat(fullPath, &st) == 0) {
                printPermissions(st.st_mode);
                printf(" %2ld %8ld  ", (long) st.st_nlink, (long) st.st_size);
                char timebuf[64];
                strftime(timebuf, sizeof(timebuf), "%b %d %H:%M", localtime(&st.st_mtime));
                printf("%s  %s\n", timebuf, entry->d_name);
            }
        } else {
            printf("%s  ", entry->d_name);
        }
    }

    if (!longFormat)
        printf("\n");

    closedir(dir);
    return 0;
}
