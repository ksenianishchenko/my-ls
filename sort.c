#include "./include/ls-header.h"

int compLex(void *a, void *b) {

  char *str1 = (char *)a;
  char *str2 = (char *)b;

  int result = strcasecmp(str1, str2);

  return result;
}


time_t getModTime (char *filname) {
  struct stat stats;
  stat(filname, &stats);

  time_t time = stats.st_mtime;

  return time;
}

int compTime(void *a, void *b) {

  time_t time1 = getModTime((char *)a);
  time_t time2 = getModTime((char *)b);

  if (time1 > time2) {
    return -1;
  } else if (time1 < time2) {
    return 1;
  } else {
    return 0;
  }
}

void sortList(t_llist *list, int (*f)(void *, void *)) {
  t_llist *current = list;
  t_llist *index = NULL;
  void *temp;
  int compIndex;

  if(list == NULL) {
    return;
  } else {
    while(current != NULL) {
      index = current->next;

      while (index != NULL) {
        compIndex = (*f)(current->data, index->data);

        if (compIndex > 0) {
          temp = current->data;
          current->data = index->data;
          index->data = temp;
        }

        index = index->next;
      }

      current = current->next;
    }
  }
}
