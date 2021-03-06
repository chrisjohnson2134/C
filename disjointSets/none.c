//chris johnson
//none.c
//this program contains no heuristics

#include <stdio.h>

struct node{
  struct node* parent;
  int value;
  int rank;
};

void make_set(struct node*,int);
void union_w_o(struct node* n1,struct node* n2);
struct node* find_set(struct node);


int main(int argc,char* argv[])
{
  printf("\ntest with no heuristics\n");
  printf("file open: %s\n",argv[1]);
  int iterations = 0,vertices = 0,edges = 0;
  int its = 0,i = 0,j = 0;
  int e1 = 0, e2 = 0;
  FILE *file;
  struct node *arr = NULL;
  file = fopen(argv[1],"r");
  if(file){
    
    printf("file opened\n\n");
    fscanf(file,"%i",&iterations);
    printf("iterations: %i\n\n",iterations);
    
    while( its <  iterations )
      {
	printf("iteration: %i\n",its);
	fscanf(file,"%i",&vertices);
	printf("vertices: %i\n",vertices);

	//reallocate memory on the heap
	arr = realloc(arr,vertices*sizeof(struct node));

	//intialize each node in the array
	for(i = 0;i < vertices;i++)
	  {
	    make_set(&arr[i],(i+1));
	  }
	
	fscanf(file,"%i",&edges);
	printf("edges: %i\n",edges);


	//union each set of edges
	for(j = 0;j < (edges*2);j+=2)
	  {
	    fscanf(file,"%i",&e1);
	    fscanf(file,"%i",&e2);
	    union_w_o(&arr[(e1-1)],&arr[(e2-1)]);
	  }

	    //open the bracket
	    printf("[ ");
	    //search for self loops
	    for(i=0;i<vertices;i++)
	      //if self loop
	      if(arr[i].value == find_set(arr[i])->value)
	    	{
	    	  printf("[");
	    	  //search for children
	    	  for(j=0;j<vertices;j++)
	    	    //if parent of child is equal to self
	    	    if(arr[i].value == find_set(*arr[j].parent)->value)
	    	      printf(" %i ",arr[j].value);
	    	  printf("]");
	    	}
	    //close bracket
	    printf(" ]");
	printf("\n\n");

    its++;
  }
}
    
fclose(file);
  
free(arr);
return 0;
}

void make_set(struct node* v,int val)
{
  v->value = val;
  v->rank = 0;
  v->parent = v;
}

void union_w_o(struct node* n1,struct node* n2)
{
  find_set(*n2)->parent = find_set(*n1);
}

struct node* find_set(struct node n)
{
  //printf("fs %i %i\n",n.parent->value,n.value);
  if(n.parent->value != n.value)
    n.parent = find_set(*n.parent);
  return n.parent;
}
