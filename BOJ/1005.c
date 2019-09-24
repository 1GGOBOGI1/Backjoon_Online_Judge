#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node_type *node_ptr;
struct node_type{
      int building_number;
      node_ptr link;
};

node_ptr buildings[1002]=NULL;
int time[1002]={0};
int max_time[1002]={0};

void insert_node(node_ptr prev, int number);
void find_answer(int num);

int main(void){
      
      int T;
      scanf("%d",&T);
      while(T--){
            int N,K;
            scanf("%d %d",&N,&K);
            for(int i=1;i<=N;i++){
                  scanf("%d",&time[i]);
            }
            while(K--){
                  int X,Y;
                  scanf("%d %d",&X, &Y);
                  insert_node(buildings[Y],X);
            }
            int W;
            scanf("%d",&W);

      }
      return 0;
}

void insert_node(node_ptr prev, int number){
      node_ptr node;
      node = (node_ptr)malloc(sizeof(struct node_type));
      if(!node)exit(1);
      node->building_number=number;
      node->link = prev->link;
      prev->link = node;
}

void find_answer(int num){
      if(!buildings[num]){
            max_time[num]=time[num];
            return ;
      }
      
}