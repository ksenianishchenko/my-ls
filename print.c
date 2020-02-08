#include "./include/ls-header.h"


void *readableFileSizeFormat(char *buf, off_t size) {
    sprintf(buf, "%ld bytes", size);
}

void printStats(char *filename, struct Options opts) {
    struct stat stats;
    stat(filename, &stats);

    printf("%s ", filename);

    if(opts.using_z == 1) {
      char *buf;
      buf = (char*)malloc(stats.st_size * sizeof(char*) + 6);
      readableFileSizeFormat(buf, stats.st_size);
      printf("%s ", buf);
    }

    if(opts.using_t == 1) {  /*Print last time mod*/
      char *buf;
      buf = ctime(&stats.st_mtime);
      printf("%s ", buf);
    }
}

void printList(t_llist *head, struct Options opts) {

    if (opts.using_t == 1) {
        sortList(head, compTime);
    } else {
      sortList(head, compLex);
    }

    while (head != NULL) {
        printStats(head->data, opts);
        head = head->next;
        puts("\n");
    }
}

void printStr(void *str) {
  printf("%s\n", (char *)str);
}
