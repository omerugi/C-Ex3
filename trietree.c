#include <stdlib.h>
//#define character size
#define CHAR_SIZE 26
#include <stdio.h>
#include "trietree.h"

//// A Trie node
struct Trie
{
    int isLeaf;	// 1 when node is a leaf node
    struct Trie* character[CHAR_SIZE];
    int counter;
};

/// Function that returns a new Trie node
struct Trie* getNewTrieNode()
{
    struct Trie* node = (struct Trie*)malloc(sizeof(struct Trie));
    node->isLeaf = 0;
    node->counter=0;
    for (int i = 0; i < CHAR_SIZE; i++)
        node->character[i] = NULL;

    return node;
}

/// Iterative function to insert a string in Trie
void insert(struct Trie *head, char* str)
{
    // start from root node
    struct Trie* curr = head;
    while (*str)
    {
        // create a new node if path doesn't exists
        if (curr->character[*str - 'a'] == NULL)
            curr->character[*str - 'a'] = getNewTrieNode();
        // go to next node
        curr = curr->character[*str - 'a'];
        // move to next character
        str++;
    } curr->counter++;
    // mark current node as leaf
    curr->isLeaf = 1;
}

/// Will build a word from input array and will insert to the trietree
void build_word(char input[], int start, int end,struct Trie* head){

    if(end == start ){return;}
    char *word = (char*)malloc(sizeof(char)*(end-start+2));

    int k =0;
    for (int i = start; i < end; ++i) {
        *(word+k) = input[i];
        k++;
    }

    if(k == 0){
        return;
    }
    *(word+k)= '\0';


    insert(head, word);

    free(word);
}

/// Iterative function separated words from the buffer
void appendtoinput(char *input, struct Trie* head,int input_len){

    int temp;
    int i =0;
    int k=2;
    int j=0;
    int temp_len = input_len;
    while ((temp = getchar()) != '\n' && temp != EOF){

        if(temp>= 97 && temp<=122){
            *(input+i) = temp;
                    i++;
        }else if(temp>= 65 && temp<=90){
            temp = temp+32;
            *(input+i) = temp;
            i++;
        } else if(temp == 32) {
            build_word(input, j, i, head);

            j=++i;
        }

        if(i == temp_len){
            TRY:
            ;
            char *tmp = (char *)realloc(input, sizeof(char)+input_len*k);
            temp_len =input_len*k;
            k++;
            if (tmp != NULL) {
                input = tmp;
            } else {
                printf("sdasd");
                goto TRY;
            }

        }
    }
    build_word(input,j,i,head);
    free(input);
}

/// Will delete and free all the nodes in the tree
void delete(struct Trie* root)
{

    for (int i = 0; i < CHAR_SIZE; i++)
    {
        if (root->character[i])
        {
            delete(root->character[i]);
        }
    }
    free(root);

}

/// Will dispaly all the word in the tree
void display(struct Trie* root, char str[], int level,struct Trie* r)
{

    if(level > sizeof(&str)){
        str =(char*) realloc(str, sizeof(&str)*2);
    }
    // If node is leaf node, it indicates end
    // of string, so a null character is added
    // and string is displayed
    if (root->isLeaf)
    {
        str[level] = '\0';
        printf("%s\t%d\n",str,root->counter);
    }

    int i;
    for (i = 0; i < CHAR_SIZE; i++)
    {
        // if NON NULL child is found
        // add parent key to str and
        // call the display function recursively
        // for child node
        if (root->character[i])
        {
            str[level] = i + 'a';
            display(root->character[i], str, level + 1,r);
        }
    }

}

/// Will reverce dispaly all the word in the tree
void displayrev(struct Trie* root, char str[], int level)
{

    if(level > sizeof(&str)){
        str =(char*) realloc(str, sizeof(&str)*2);
    }
    // If node is leaf node, it indicates end
    // of string, so a null character is added
    // and string is displayed
    if (root->isLeaf)
    {
        str[level] = '\0';
        printf("%s\t%d\n",str,root->counter);
    }

    int i;
    for (i = CHAR_SIZE-1; i >= 0; i--)
    {
        // if NON NULL child is found
        // add parent key to str and
        // call the display function recursively
        // for child node
        if (root->character[i])
        {
            str[level] = i + 'a';
            displayrev(root->character[i], str, level + 1);
        }
    }

}

/// Will call the display function and free str
void disdis(struct Trie* root, char str[], int level){
    display(root,str,level,root);
    free(str);
}
/// Will call the displayrev function and free str
void disdisrev(struct Trie* root, char str[], int level){
    displayrev(root,str,level);
    free(str);
}

