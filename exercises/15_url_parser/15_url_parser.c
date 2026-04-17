#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/**
 * URL参数解析器
 * 输入：包含http/https超链接的字符串
 * 输出：解析出所有的key-value键值对，每行显示一个
 */

int parse_url(const char* url) {
    int err = 0;
    // TODO: 在这里添加你的代码
    if(url == NULL){
        err = -1;
        goto exit;
    }
    // 查找 ? 的位置（参数开始）
    char *question_mark = strchr(url, '?');
    if (question_mark == NULL) {
        // 没有参数
        err = -1;
        goto exit;
    }
    // 复制参数字符串
    char *params = strdup(question_mark + 1);
    if (params == NULL) {
        err = -1;
        goto exit;
    }
    // 分割多个参数（用 & 分隔）
    char *token = strtok(params, "&");
    
    while (token != NULL) {
        // 查找 = 分隔键和值
        char *equals = strchr(token, '=');
        
        if (equals != NULL) {
            *equals = '\0';  // 分割键和值
            char *key = token;
            char *value = equals + 1;
            
            // 输出键值对
            printf("%s = %s\n", key, value);
        } else {
            // 没有 = 的参数，只有键没有值
            printf("%s = \n", token);
        }
        
        token = strtok(NULL, "&");//继续分割上次那个字符串，从上次结束的地方开始
    }
    free(params);
exit:
    return err;
}

int main() {
    const char* test_url = "https://cn.bing.com/search?name=John&age=30&city=New+York";

    printf("Parsing URL: %s\n", test_url);
    printf("Parameters:\n");

    parse_url(test_url);

    return 0;
}