#include"linkedlist.h"

char array[8][10];
char temp[10];
char *pTemp=&(temp[0]);
char *pArray=&(array[0][0]);


struct SNode *New_pNode(int n, char c) {
    struct SNode *pNode=(struct SNode*)malloc(sizeof(struct SNode));
    pNode->c=c;
    pNode->pNext=NULL;
    pNode->pLCHild=NULL;
    pNode->pRChild=NULL;
    pNode->n=n;
    
}


struct SList *LL_new(struct SNode* pNode) {
    struct SList *list=(struct SList*)malloc((sizeof(struct SList)));
    list->head=pNode;

    return list;

}

void LL_print(struct SList* list) {
    //printf("%d\n",list->head->n);
    struct SNode *tmp=list->head;
    
    while(tmp!=NULL) {
        printf("%d\n",tmp->n);
        tmp=tmp->pNext;
    } 

    // printf("%d\n",list->head->n);
    
}


void Sorted_Add(struct SList**ppL, struct SNode* pNode) {

    struct SNode* pSentinel;
    struct SNode* pCurrent=(*ppL)->head;
    while(pCurrent) {
        if(pNode->n<=(*ppL)->head->n) { 
            //adding pNode to the beginning of the list
            pNode->pNext=(*ppL)->head;
            (*ppL)->head=pNode;
            break;
        }
        else {
            if(pNode->n>pCurrent->n) {
                pSentinel=pCurrent;
                pCurrent=pCurrent->pNext;
                if(pCurrent==NULL) {
                    pSentinel->pNext=pNode;
                    break;
                }
            }
            else {
                pNode->pNext=pCurrent;
                pSentinel->pNext=pNode;
                break;
            }
        }




     
}
}



struct SList *make_tree(struct SList** list) {
   
    printf("head now %d\n",(*list)->head->n);

    struct SNode *tmp= (*list)->head;
    struct SList *pTree=LL_new(tmp);
       


    while(tmp!=NULL) {
    struct SNode *pNode=New_pNode((tmp->n)+(tmp->pNext->n),'\0');
   // printf("the number we added %d\n", tmp->n+tmp->pNext->n);

    pTree->head=pNode;
    printf("sum now %d\n",pTree->head->n);
    printf("------");
    pNode->pLCHild=tmp;
    tmp=tmp->pNext;
    pNode->pRChild=tmp;
    tmp=tmp->pNext;
    (*list)->head=tmp;
    Sorted_Add(list,pNode);
    tmp=(*list)->head;
    


    }
    printf("the root iss %d\n",pTree->head->n);
    return pTree;

}



void TraverseTree(struct SNode *pNode,char *pTemp) {
    //everytime we send pTemp -> to know where to put 0/1 (48/49), and maybe override the value

    if(pNode->pLCHild) {
        *pTemp='0'; // value 48 
        TraverseTree(pNode->pLCHild,pTemp+1);
    }  
   

    if(pNode->pRChild) {
        *pTemp='1'; // value 49
        TraverseTree(pNode->pRChild,pTemp+1);
    }

    else {
     *pArray=pNode->c; // the letter is put to the array
    *(pArray+1)=0; // why ?? 0 at the end makes letter string
    *pTemp=0; // ? strlen copies till it sees 0? (everything before 0 is string now)
    strcpy(pArray+2,temp); // destination -> source
    pArray+=10; // ptr now points to next row of array

    }

    }

void PrintTable() {

    for (int i=0; i<8; i++) {
        printf("letter:%c| ",array[i][0]);
       

        for (int j=2; j<10; j++) {
            printf("%c",array[i][j]);
        }
        printf("\n");
    }

    

   
}

char * GiveBinaryFromTable(char c) {
    char tmp[8]; // temporary array to store the bin value of letter 
    char *code=(char *)malloc(8);
    for (int i=0; i<8; i++) {
      
        if(c==array[i][0]) {
            for (int j=2, k=0; j<9; j++, k++) {
              
                tmp[k]=array[i][j];
            }
            
            strcpy(code,tmp); // copy from temporary array to string (char *)
        }
    }
    return code;
}

char GiveLetterFromTable (char *c){

    char *tmp=(char *)malloc(8);
    int index=0;

    
for (int j=0; j<8; j++) {
    for (int i=2; i<9; i++) {
        tmp[index]=array[j][i];
        index ++;
    }
    if(strcmp(tmp,c)==0) return array[j][0];
    else index=0;
    
}

    return 0;
}





