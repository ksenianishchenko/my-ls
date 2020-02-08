#include "./include/ls-header.h"

void init_opts(struct Options *opts) {
    opts->using_a = 0;
    opts->using_z = 0;
    opts->using_t = 0;
    opts->using_R = 0;
};

struct Options get_opts(char *str) {
    struct Options opts;
    init_opts(&opts);

    while(*str != '\0') {
      switch(*str) {
          case 'a':
            opts.using_a = 1;
            break;
          case 'z':
            opts.using_z = 1;
            break;
          case 't':
            opts.using_t = 1;
            break;
          case 'R':
            opts.using_R = 1;
            break;
      };

      str++;
    };

    return opts;
};

char *paramsToString(int argc, char **argv) {
    char *str;
    int n = 0;
    int argvLen = 0;

    for (int i = 1; i < argc; ++i) {
        argvLen = argvLen + strlen(argv[i]);
    };

    str = malloc(sizeof(char) * (argvLen + argc));

    for (int i = 1; i < argc; i++) {
        int tempLeng = strlen(argv[i]);

        for (int j = 0; j < tempLeng; j++) {
            str[n] = argv[i][j];
            n++;
        };

    };

    str[n] = '\0';

    return str;
};
