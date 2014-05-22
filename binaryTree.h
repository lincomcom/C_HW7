#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#define MAXTREE 100

typedef int Tree;/*tree type=index into the three record*/
#define NIL ((Tree)-1)/*invalid tree */
typedef char* Key;/* key type is string */
static Tree left[MAXTREE], right[MAXTREE]; /* left and right childern*/
static Key key[MAXTREE] = { NULL }; /* "name" of each node*/
static int treeCount = 0; /* total number of tree nodes allocated*/
static int level = 0 ;/* level of root in part2 is 0*/

Tree MakeNewNode(Key k, Tree l, Tree r);/* construct tree */
void PrintIndentedTree(Tree t, int level);/* print part1 */
void PrintSidewaysTree(Tree t, char prefix[ ]);/* print part2 */
void PrintPrefix(char cumulative[], int level);/* print prefix of part2 */

#endif // BINARYTREE_H_INCLUDED
