#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"linkedlist.h"


extern char array[8][10];
extern char temp[10];
extern char *pTemp;
extern char *pArray;

int main() {
FILE *fptext=fopen("text.txt","r");
int array[256];
for(int i=0; i<256; i++)  array[i]=0;
float fSum=0;
char c;

while((c=fgetc(fptext))!=EOF) {
    printf("%c",c);
    fSum++;
    array[c]++; 
}
puts("");

printf("\n\n");

printf("length of textfile is %d\n",(int)fSum);

fclose(fptext);
struct SNode *pNode;
pNode=New_pNode(array['s'],'s');
struct SNode *pNode1;
 pNode1=New_pNode(array['i'],'i');
struct SNode *pNode2;
pNode2=New_pNode(array[' '],' ');
struct SNode *pNode3;
pNode3=New_pNode(array['t'],'t');
struct SNode *pNode4;
pNode4=New_pNode(array['o'],'o');
struct SNode *pNode5;
pNode5=New_pNode(array['n'],'n');
struct SNode *pNode6;
pNode6=New_pNode(array['d'],'d');
struct SNode *pNode7;
pNode7=New_pNode(array['m'],'m');




struct SList *list;
list=LL_new(pNode);


Sorted_Add(&list,pNode1);
Sorted_Add(&list,pNode2);
Sorted_Add(&list,pNode3);
Sorted_Add(&list,pNode4);
Sorted_Add(&list,pNode5);
Sorted_Add(&list,pNode6);
Sorted_Add(&list,pNode7);

 LL_print(list);


 struct SList *pTree=make_tree(&list);

 TraverseTree(pTree->head,pTemp);

 PrintTable(); // prints my array (table) where we have letters and their binary representation


// // DELETE BINARYTEXT FILE, OR JUST DELETE WHATS INSIDE to check 


 fptext=fopen("text.txt","r"); // open my  file where i have "si mon tonton ..."
 FILE *fpbin=fopen("binarytext","w"); // create new file to store binary code of text

 char a;
 while((a=fgetc(fptext))!=EOF) { // reading chars one by one
    
     printf("%c-",a);

 fputs(GiveBinaryFromTable(a),fpbin); // put corresponding string in binary form into file
 printf("%s\n",GiveBinaryFromTable(a));

 }




// BURA GEDER DUZ ISHLEYIR 

// BU PART TAM DEYIL
// fclose(fpbin);
// fpbin=fopen("binarytext","r");
// FILE *fptext1=fopen("text1.txt", "w");

// char *binary=(char *)malloc(8);
// char character;
// int index=0;


// printf("I START \n");


// while((character=fgetc(fpbin))!=EOF) {
//     binary[index]=character;
//     index++;

//     printf("binay repr %s\n",binary);
//     if(GiveLetterFromTable(binary)=='0') {
//     printf("every is OK \n");

        
//         continue;
//     }
//     else {
//         printf("%s-",binary);
//         fputc(GiveLetterFromTable(binary),fptext1);
//         printf("%c\n",GiveLetterFromTable(binary));
//         index=0;
//     }
// }

// BU TAM OLMAYAN PART GURTARIR
    return 0;

}