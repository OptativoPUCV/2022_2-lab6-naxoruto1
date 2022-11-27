#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  int fila[10];
  int columna[10];
  int submatriz[10];
  int i, o, p;
  int x, y, z; //o-k
  
  for (int i=0; i<9; i++){
    for (int x=0; x<10; x++) fila[x]= 0;
    for (int o=0; o<9; o++){
      if (n->sudo[i][o] != 0){
        if (fila[n->sudo[i][k]] == 1) return 0;
        else fila[n->sudo[i][k]]= 1;
      }
    }
  }

  for (int i=0; i<9; i++){
    for (int y=0; y<10; y++) columna[y]= 0;
    for (int o=0; o<9; o++){
      if (n->sudo[o][i] != 0){
      	if (columna[n->sudo[o][i]] == 1) return 0;
        else columna[n->sudo[o][i]]= 1;
      }
    }
  }

  for (int i=0; i< 9; i++){
    for (int z=0; z<10; z++) submatriz[z]= 0;
    for (int o= 0; o< 9; o++){
      int i2= 3*(i/3)+ (o/3);
      int k2= 3*(i%3)+ (o%3);
      if (n->sudo[i2][k2] != 0){
        if (submatriz[n->sudo[i2][k2]] == 1) return 0;
        else submatriz[n->sudo[i2][k2]]= 1;
      }
    }
	}
  return 1;
}


List* get_adj_nodes(Node* n){
    List* lista=createList();
    int i;
    int k;
    for (i = 0; i < 9; i++)
    {
      for (k = 0; k < 9; k++)
      {
        if (n->sudo[i][k] == 0)
        {
          for (int newValue = 1; newValue < 10; newValue++)
          {
            n->sudo[i][k] = newValue;
            if (is_valid(n))
            {
              Node* adjNode = copy(n);
              pushBack(lista, adjNode);
            }
          }
          n->sudo[i][k] = 0;
          return lista;
        }
      }
    }
    return lista;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/