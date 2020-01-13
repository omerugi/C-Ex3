#include <stdlib.h>
#define character size
#define CHAR_SIZE 26
#include <stdio.h>
#include "trietree.h"

int main(int argc, char **argv)
{
    int temp;
    scanf("%d",&temp);

    char *input;
    input = (char *) malloc(sizeof(char) * 16);
    struct Trie* head = getNewTrieNode();
    int input_len = 10;
    appendtoinput(input, head,input_len);

    if(argc == 2 && argv[1][0] == 'r' ){
        char *str1;
        str1 = (char *) malloc(sizeof(char) * 16);
        disdisrev(head,str1,0);
    } else{
        char *str;
        str = (char *) malloc(sizeof(char) * 10);
        disdis(head,str,0,10);
    }

    delete(head);
    return 0;
}
