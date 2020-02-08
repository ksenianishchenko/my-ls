#include "./include/ls-header.h"

int canRecurseDir(char *parent, char *current) {

    struct stat stats;

    if (!strcmp(".", current) || !strcmp("..", current)) {
        return 0;
    }

    char *path = malloc(strlen(current) + strlen(parent) + 2);
    sprintf(path, "%s/%s", parent, current);

    if (stat(path, &stats) < 0) {
        perror(path);
    }

    return S_ISDIR(stats.st_mode);
}

void *recurseDirs(char* dir, struct Options opts) {
    DIR* folder = opendir(dir);
    struct dirent* entry;
    t_llist *linkedList = NULL;

    while ((entry = readdir(folder))) {

        add_llist_root(&linkedList, entry->d_name, sizeof(struct dirent));
        if (canRecurseDir(dir, entry->d_name)) {

            char *next = malloc(strlen(dir) + strlen(entry->d_name) + 2);
            sprintf(next, "%s/%s", dir, entry->d_name);

            recurseDirs(next, opts);

            free(next);

        }
    }

    printList(linkedList, opts);

    closedir(folder);
}


int filesInDir(char *path, int argc, char **argv, struct Options opts) {
    DIR *folder = opendir(path);
    struct dirent *entry = NULL;

    t_llist *linkedList = NULL;

    if(folder == NULL) {
        puts("Unable to read directory");
        return(1);
    };

    while((entry=readdir(folder))) {
        if (opts.using_a == 1 && opts.using_R == 0) {

            add_llist_root(&linkedList, entry->d_name, sizeof(struct dirent));

        } else if (opts.using_R == 1) {

            recurseDirs(".", opts);
            break;

        } else {

            if(entry->d_name[0] == '.') {
                continue;
            } else {

                add_llist_root(&linkedList, entry->d_name, sizeof(struct dirent));

            }

        }
    }

    printList(linkedList, opts);

    closedir(folder);
    return 0;
};

int main(int argc, char *argv[]) {
    char *str = paramsToString(argc, argv);

    filesInDir(".", argc, argv, get_opts(str));

    return(0);
};
