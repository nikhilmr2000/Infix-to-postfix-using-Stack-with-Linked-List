#include <stdio.h>
#include<stdlib.h>
int main() {
    
    struct stacknode{
        char value;
        struct stacknode *next;
    };
    
    struct stacknode *topstack=NULL;
    
    void push(char element){
        struct stacknode *newstack;
        newstack=(struct stacknode *)malloc(sizeof(struct stacknode));
        newstack->value=element;
        newstack->next=topstack;
        topstack=newstack;
        
    }
    
    void pop(){
        
        struct stacknode *tempstack;
        tempstack=topstack;
        topstack=topstack->next;    
        free(tempstack);
        
        
    }
    
    void display(){
        
        struct stacknode *newtop;
        newtop=topstack;
        
        while(newtop!=NULL){
            printf("%c ",newtop->value);
            newtop=newtop->next;
        }
        
    }
    
    
    char expression[9]={'(','a','+','b',')','*','c','+','d'};
    
    char postfix[9];int t=0;
    
    for(int i=0;i<9;i++){
        
        if(expression[i]>='a' && expression[i]<='z'){
            postfix[t]=expression[i];
            t++;
        }
        else{
            
            if(expression[i]=='(' || expression[i]==')'){
                
                if(expression[i]=='('){
                  
                    push(expression[i]);
                }
                
                else if(expression[i]==')'){
                   
                   
                    if(topstack!=NULL){
                      
                       while(topstack->value!='(' && topstack!=NULL){
                           postfix[t]=topstack->value;
                           t++;
                           pop();
                       }
                       
                       
                      pop();
                     
                        
                    }
                    else{
                        //Do Nothing;
                    }
                }
                
            }
            
            
            
            else if(expression[i]=='^'){
                if(topstack!=NULL){
                     if(topstack->value=='('){
                        push(expression[i]);
                    }   
                    else if(topstack->value=='^'){
                        push(expression[i]);
                    }
                    else{
                        push(expression[i]);
                    }
                }
                
                
            }
            
            
            else if(expression[i]=='*' || expression[i]=='/'){
                
                if(topstack!=NULL){
                    if(topstack->value=='('){
                     
                     push(expression[i]);
                  }
                    else if(topstack->value=='^' || topstack->value=='*' || topstack->value=='/'){
                    
                   
                    while((topstack->value=='^' || topstack->value=='*' || topstack->value=='/')&& topstack!=NULL){
                        
                        if(topstack->next==NULL){
                            postfix[t]=topstack->value;
                            t++;
                            topstack=NULL;
                            push(expression[i]);
                            
                            break;
                        }
                        else{
                            postfix[t]=topstack->value;
                            t++;
                            pop();     
                        }
                       
                        
                    }
                    
                    
        
                }
                else{
                    push(expression[i]);
                }
                
                }
                else{
                    
                    push(expression[i]);
                }
                
            }
            
           else if(expression[i]=='+' || expression[i]=='-'){
                
                if(topstack!=NULL){
                    if(topstack->value=='('){
                     push(expression[i]);
                    }
                    else if(topstack->value=='^' || topstack->value=='*' || topstack->value=='/' || topstack->value=='+' || topstack->value=='-'){
                    
                   
                    while((topstack->value=='^' || topstack->value=='*' || topstack->value=='/' || topstack->value=='+' || topstack->value=='-') && topstack!=NULL){
                        
                        if(topstack->next==NULL){
                            postfix[t]=topstack->value;
                            t++;
                            topstack=NULL;
                            push(expression[i]);
                            break;
                        }
                        else{
                            postfix[t]=topstack->value;
                            t++;
                            pop();     
                        }
                    }
    
                }
                else{
                    push(expression[i]);
                }
                
                }
                else{
                    push(expression[i]);
                }
                
            }
            
            
        }
        
    }
    
    
    
    while(topstack!=NULL){
        postfix[t]=topstack->value;
        t++;
        topstack=topstack->next;
    }
    
    
    for(int i=0;i<t;i++){
       printf("%c",postfix[i]);
    }
    
}
