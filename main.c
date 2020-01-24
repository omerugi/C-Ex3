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
        disdisrev(head,0);
    } else{
        disdis(head,0);
    }

    delete(head);
    return 0;
}
