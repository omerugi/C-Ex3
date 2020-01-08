//
// Created by dor on 08/01/2020.
//

#ifndef EX_4_TRIETREE_H
#define EX_4_TRIETREE_H

struct Trie;
struct Trie* getNewTrieNode();
void insert(struct Trie *head, char* str);
void build_word(char input[], int start, int end,struct Trie* head);
void appendtoinput(char *input, struct Trie* head,int input_len);
void display(struct Trie* root, char str[], int level,struct Trie* r);
void displayrev(struct Trie* root, char str[], int level);
void disdis(struct Trie* root, char str[], int level);
void disdisrev(struct Trie* root, char str[], int level);
void delete(struct Trie* root);

#endif //EX_4_TRIETREE_H
