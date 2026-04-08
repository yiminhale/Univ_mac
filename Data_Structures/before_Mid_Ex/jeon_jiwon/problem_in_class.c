#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 256
#define MAX_STR   256


typedef struct {
    int a[MAX_ITEMS];
    int top; 
} Stack;

static void st_init(Stack* s){ s->top = -1; }
static int  st_empty(const Stack* s){ return s->top < 0; }
static int  st_full (const Stack* s){ return s->top+1 >= MAX_ITEMS; }
static void st_push (Stack* s, int v){ if(!st_full(s)) s->a[++s->top] = v; }
static int  st_pop  (Stack* s){ return st_empty(s) ? -1 : s->a[s->top--]; }


typedef struct TableNode {
    char  raw[MAX_STR]; 
    Stack order;        
    struct TableNode* next;
} TableNode;

typedef struct {
    TableNode *front, *back;
    int size;
} Queue;

static void q_init(Queue* q){ q->front = q->back = NULL; q->size = 0; }
static int  q_empty(Queue* q){ return q->size == 0; }

static void q_push(Queue* q, const char* raw, const Stack* st){
    TableNode* n = (TableNode*)malloc(sizeof(TableNode));
    strncpy(n->raw, raw, MAX_STR-1); n->raw[MAX_STR-1] = '\0';
    n->order = *st; 
    n->next = NULL;
    if(q->back) q->back->next = n; else q->front = n;
    q->back = n; q->size++;
}

static int q_pop(Queue* q, TableNode* out){
    if(q_empty(q)) return 0;
    TableNode* n = q->front;
    if(out) *out = *n; 
    q->front = n->next;
    if(!q->front) q->back = NULL;
    free(n);
    q->size--;
    return 1;
}


static const char* menu_name(int d){
    switch(d){
        case 1: return "Ice cream";
        case 2: return "Bibimbab";
        case 3: return "Bulgogi";
        case 4: return "Coffee";
        case 5: return "Noodle";
        default: return NULL;
    }
}


static int build_stack_from_raw(const char* raw, Stack* st){
    st_init(st);
    int any = 0;
    for(const char* p = raw; *p; ++p){
        if(isspace((unsigned char)*p)) continue;
        if('1' <= *p && *p <= '5'){
            st_push(st, *p - '0');
            any = 1;
        } else {
           
        }
    }
    return any; 
}


static void print_stat(Queue* q){
    printf("Stat : ");
    if(q_empty(q)){
        printf("(0)\n\n");
        return;
    }
   
    for(TableNode* n = q->front; n; n = n->next){
        printf("%s%s", n->raw, (n->next ? " " : " "));
    }
    printf("(%d)\n\n", q->size);
}

int main(void){
    Queue line; q_init(&line);

    while(1){
        int cmd;
        printf("Order (0), Serve (1), Exit (2) : ");
        if(scanf("%d", &cmd) != 1) break;

        if(cmd == 2){
            
            break;
        }
        else if(cmd == 0){
            
            char raw[MAX_STR];
            printf("Order : ");
            
            int ch; while((ch=getchar())!='\n' && ch!=EOF){} 
            if(!fgets(raw, sizeof(raw), stdin)){
               
                print_stat(&line);
                continue;
            }
            
            raw[strcspn(raw, "\r\n")] = '\0';

            Stack st;
            if(build_stack_from_raw(raw, &st)){
                q_push(&line, raw, &st);
            }
            print_stat(&line);
        }
        else if(cmd == 1){
            
            TableNode t;
            if(q_pop(&line, &t)){
                printf("Serve : ");
                int first = 1;
                while(!st_empty(&t.order)){
                    int d = st_pop(&t.order);
                    const char* name = menu_name(d);
                    if(name){
                        if(!first) printf(", ");
                        printf("%s", name);
                        first = 0;
                    }
                }
                printf("\n");
            } else {
                
                printf("Serve : \n");
            }
            print_stat(&line);
        }
        else{
           
            print_stat(&line);
        }
    }

    
    TableNode tmp;
    while(q_pop(&line, &tmp)){ /* noop */ }

    return 0;
}
