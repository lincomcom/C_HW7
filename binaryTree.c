#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"binaryTree.h"

Tree MakeNewNode(Key k, Tree l, Tree r) {
Tree t;
/* no more tree nodes can be allocated */
if (treeCount >= MAXTREE) {
    return NIL;
}
for (t = 0; t < MAXTREE; t++) {
    /* no name, assume available */
    if (key[t] == NULL) {
        key[t] = k; /* set node name to new key k */
        left[t] = l;  /* set left child */
        right[t] = r; /* set right child */
        treeCount++;
        return t;
    }
} /* we should never drop out of this loop */
return t;
}



/*part1*/
void PrintIndentedTree(Tree t, int level){
/*base condition*/
if (t == NIL) return;

/*print blank of 8 space*/
int i;
for(i=0; i<level; i++){
    printf("        ");
}
level++;
/*print name of node*/
printf("%s\n", key[t]);
/*left recursion*/
PrintIndentedTree(left[t], level);
/*right recursion*/
PrintIndentedTree(right[t], level);
}


void PrintPrefix(char cumulative[], int level){
    int i;
    for(i=0; i<level-2; i++){
        /* switch direction, when L followed by R or R followed by L */
        if(cumulative[i]!=cumulative[i+1])
            printf("  | ");
        else
            printf("    ");
    }
}

/*part2*/
void PrintSidewaysTree(Tree t, char prefix[]){
/*base condition*/
if (t == NIL) return;

/*cumulative char array as stack*/
static char cumulative[MAXTREE];
/*into PrintSidewaysTree level++,level of A = 1*/
level++;

/*push prefix into cumulative*/
strncat( cumulative, prefix, 2);

/*right recursion*/
PrintSidewaysTree(right[t], "R");

/*if the prefix is empty=root.*/
if(cumulative[0]=='\0')
    printf("%s-+\n", key[t]);
/* !=root*/
else{
    /* print prefix*/
    PrintPrefix( cumulative, level);

    /* it's leaf*/
    if(left[t]==NIL&&right[t]==NIL)
        printf("  +-%s\n", key[t]);
    /* it's not leaf*/
    else
        printf("  +-%s-+\n", key[t]);
}

/*left recursion*/
PrintSidewaysTree(left[t],"L");

/*out of PrintSidewaysTree level--,level of A = 1*/
level--;

/* pop cumulative, shit Null character of 1 element*/
int cumLen=strlen(cumulative);
cumulative[cumLen-1]='\0';
}
