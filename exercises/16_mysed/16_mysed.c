#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

int parse_replace_command(const char* cmd, char** old_str, char** new_str) {
    if (cmd[0] != 's' || cmd[1] != '/') {
        return -1;
    }

    // TODO: 在这里添加你的代码
    const char* old_start = cmd+2;
    const char* temp = strchr(old_start, '/');
    if (temp == NULL)
    {
        return -1;
    }
    const char* new_start = temp+1;
    const char* temp2 = strchr(new_start, '/');

    size_t old_len = temp-old_start;
    size_t new_len = temp2-new_start;

    *old_str = (char*)malloc(old_len+1);
    *new_str = (char*)malloc(new_len+1);
    if(old_str == NULL || new_str == NULL){
        free(old_str);
        free(new_str);
        return -1;
    }
    strncpy(*old_str, old_start, old_len);
    (*old_str)[old_len] = '\0';
    strncpy(*new_str, new_start, new_len);
    (*new_str)[new_len] = '\0';

    return 0;
}

void replace_first_occurrence(char* str, const char* old, const char* new) {
    // TODO: 在这里添加你的代码
    if(str == NULL || old == NULL || new == NULL)
        return;
    char *pos = strstr(str, old);
    if(pos == NULL)
        return;
    size_t old_len = strlen(old);
    size_t new_len = strlen(new);
    size_t len = strlen(pos+old_len);

    memmove(pos+new_len, pos+old_len, len+1);
    memcpy(pos, new, new_len);
}

int main(int argc, char* argv[]) {
    const char* replcae_rules = "s/unix/linux/";

    char line[MAX_LINE_LENGTH] = {"unix is opensource. unix is free os."};

    char* old_str = NULL;
    char* new_str = NULL;
    
    if (parse_replace_command(replcae_rules, &old_str, &new_str) != 0) {
        fprintf(stderr, "Invalid replace command format. Use 's/old/new/'\n");
        return 1;
    }

    
    replace_first_occurrence(line, old_str, new_str);
    fputs(line, stdout);

    free(old_str);
    free(new_str);
    return 0;
}
