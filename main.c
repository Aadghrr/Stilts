#include<stdio.h>
#include<string.h>

//Node in the AST
struct AST {
	bool isCall;
	union {
		int value;
		struct {
			char const * operator;
			size_t countOperands;
			struct AST * operands;
		} call;
	};
};

//Unified return type -- correct to refer to this as value in the AST
typedef ret struct {
	int i;
	float f;
	char *c;
	char c1;
};
//Unified function type
typedef int (*Func)(struct AST *,size_t);

//sum function
int sum(struct AST *params,size_t num) {
	int i=0;
	while(num>0){
		--num;
		i+=params[num].value;
	}
	return i;

//Function lookup table -- can definitely improve this
static Function const funcs[] ={sum};
static char const * const func_names[] = {"+"};

//Lookup function for the arrays above
Function lkp(char const *n){
	size_t i = sizeof(funcs)/sizeof(funcs[0]);
	while(i>0){
		--i;
		if(strcmp(n,func_names[i])==0){
			return funcs[i];
		}
	}
	exit(1);
}

//Evalute abstract syntax tree
struct AST *eval(struct AST *node){
	if(! node->isCall){
		return node;
	}
	Function f = lkp(node->call.operator);
	size_t ops;
	for(ops=0;ops < code->call.countOperands;++ops){
		node->call.operands[ops] = *eval(&(node->call.operands[ops]));
	}
	node->isCall=false;
	node->value=f(node->call.operands,node->call.countOperands);
	return node;
}

struct AST *parser(char *s){
	//The parser gets a string like sum 1 2
	//Needs to break that into a singly linked list of strings
	//then translate that into an array of 3 AST nodes
	//{.isCall=false, .value=1}, {.iC=f, .v =2},etc.
	//
	struct Ast *r;
	char *t,*u;
	t = strdup(s);
	u = strsep(&t," ");
	while((tok = strsep(&t," ")) != NULL){
		
	}
	return r;

int main(){
	char *s;
	char *t, *u;
	printf("Version 0.0.1\n");
	while(1){
		printf("-> ");
		fgets(s,24,stdin);
		struct AST *par=parse(s);
		struct AST *res=eval(&par[3]);
		printf("%d\n",res->value);
	}
	return 0;
}

