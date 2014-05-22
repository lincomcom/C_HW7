#include <stdio.h>
#include <stdlib.h>
#include"binaryTree.h"

int main()
{
    /*construct tree*/
    Tree root=MakeNewNode("A",
                  MakeNewNode("B",
                      MakeNewNode("C",
                          MakeNewNode("H",
                              MakeNewNode("P", NIL, NIL), NIL),
                          MakeNewNode("I",
                              MakeNewNode("R", NIL, NIL),
                              MakeNewNode("Q", NIL, NIL)
                                      )
                                  ),
                      MakeNewNode("D",
                          MakeNewNode("J", NIL, NIL),
                          MakeNewNode("K", NIL, NIL)
                                  )
                              ),
                  MakeNewNode("E",
                      MakeNewNode("F",
                          MakeNewNode("L", NIL, NIL),
                          MakeNewNode("M", NIL, NIL)
                                  ),
                      MakeNewNode("G",
                          MakeNewNode("N", NIL, NIL),
                          MakeNewNode("O", NIL, NIL)
                                  )
                              )
                          );





    /*part1*/
    printf("part1\n");
    PrintIndentedTree( root, 0);


    /*part2*/
    printf("part2\n");
    PrintSidewaysTree( root, "");
    return 0;
}
