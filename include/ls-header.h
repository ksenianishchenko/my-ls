#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>

struct Options {
    int using_a;
    int using_z;
    int using_t;
    int using_R;
};

typedef struct filesInfo {
    char *name;
    off_t size;
    time_t time;
}t_file;

typedef struct LinkedList {
  void                *data;
  struct LinkedList   *next;
}t_llist;

void init_opts(struct Options *opts);
struct Options get_opts(char *str);
char *paramsToString(int argc, char **argv);
void *add_llist_root(t_llist **head, void *new_data, size_t data_size);
void *readableFileSizeFormat(char *buf, off_t size);
void printStats(char *filename, struct Options opts);
void printList(t_llist *head, struct Options opts);
void printStr(void *str);
time_t getModTime (char *filname);
int compTime(void *a, void *b);
int compLex(void *a, void *b);
void sortList(t_llist *list, int (*f)(void *, void *));
