#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct SNode {
char c;
int n;
struct SNode *pNext;
struct SNode *pLCHild;
struct SNode *pRChild;

};


struct SList {
struct SNode *head;

};


struct SNode *New_pNode(int n,char c);
struct SList *LL_new(struct SNode* pNode);
void Sorted_Add(struct SList** ppL, struct SNode* pNode);
void LL_print(struct SList* list);

struct SList *make_tree(struct SList** list);
void TraverseTree(struct SNode *pNode,char *pTemp);
void PrintTable();

char *GiveBinaryFromTable(char c);
char GiveLetterFromTable (char *c);
