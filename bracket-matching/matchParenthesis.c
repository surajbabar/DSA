#include "../stack-with-memcpy/stackLib.h"
#include "matchParenthesis.h"
#include <string.h>
int doBracketMatch(char* data){
	stack* Stack = create(sizeof(char),strlen(data));
	int index;
	for(index = 0; index<strlen(data); index++)
		switch(data[index]){
		    case '{' :
		    case '[' :
		    case '(' :
	            push(Stack,&data[index]);
	            break;
		    case '}' :
	            if(*(char*)top(Stack) == '{'){ pop(Stack) ;break;}
	            return 0;
		    case ']' :
	            if(*(char*)top(Stack) == '['){ pop(Stack) ;break;}
	            return 0;
		    case ')' :
	            if(*(char*)top(Stack) == '('){ pop(Stack) ;break;}
	            return 0;
	};
	return Stack->top!=-1?0:1;
};