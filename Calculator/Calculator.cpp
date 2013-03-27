#include "Calculator.h"



int main(){
    Scanner scan;
    std::stack<Token> stk;
    std::queue<Token> que;
    while(true){
        std::cout<<"Welcome to the calculator! (q to quit)"<<std::endl;
        std::cout<<"Please insert an expression to be calculated:"<<std::endl;
        Token token=scan.getNextToken();

        //Begin shunting algorithm
        std::cout<<"Begin parsing!"<<std::endl;
        std::cout<<token<<std::endl;
        while(token.GetType()!=Type::EOL){
            if (token.GetType()==Type::NUMBER || token.GetType()==Type::FRACTION){
                que.push(token);
            }

            //If stack is not empty and the precedence of the op coming in is less than the op on stack
            //pop stack to que and push new op to stack
            else if (!stk.empty()&&(token.GetType()==Type::ADDOP && stk.top().GetType()==Type::MULTOP)){
                que.push(stk.top());
                stk.pop();
                stk.push(token);
            }

            else{
                stk.push(token);
            }
            token=scan.getNextToken();
        }


    }
    return 0;
}
