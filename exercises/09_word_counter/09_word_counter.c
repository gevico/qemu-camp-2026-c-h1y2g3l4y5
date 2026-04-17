#include <stdio.h>

int main() {
    //char str[]="Don't ask what your country can do for you, but ask what you can do for your country.";
    char str[]=",,,....,,,.... ,,,..  ..... ..... ,,,,, .,  ,.";
    int wordCount = 0;
    // TODO: 在这里添加你的代码
    int i = 0;
    int inword = 0;
    while(str[i] != '\0'){
        if(str[i] == ' '){
            inword = 0;
        }else if((str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z' && str[i] >= 'A')){
            if(inword == 0){
                inword = 1;
                wordCount++;
            }
        }
        i++;
    }
    
    printf("单词数量: %d\n", wordCount);
    
    return 0;
}