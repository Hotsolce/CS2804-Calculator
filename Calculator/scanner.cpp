#include "scanner.h"


Token Scanner::getNextToken(){
    //std::ifstream file("program.txt");


        std::getline(std::cin, line);
        //Press q to quit
        if (line.compare("q")==0 || line.compare("Q")==0){
            std::cout<<"See ya!"<<std::endl;
            exit(EXIT_SUCCESS);
        }
        else{
            if (!tokens.empty()){
                Token toRet=tokens.front();
                tokens.pop();
                return toRet;
            }
            std::cout<<"line:"<<line<<std::endl;
            Token toRet=tokens.front();
            tokens.pop();
            return toRet;
        }

}

void Scanner::tokenize(){
    std::string temp;
    Token token(Type::EOL,"");
    std::cout<<"line:"<<line<<std::endl;
    for (unsigned int idx=0; idx<line.length();++idx){
    //Skip White Space
        std::cout<<"idx:"<<idx<<std::endl;

        if (line.at(idx)==' '){
            //std::cout<<"First if"<<std::endl;
            ++idx;
        }

        else{
            temp+=line.at(idx);
        }

    //Add or Subtract
        if (temp.compare("+")==0 || temp.compare("-")==0){
            //std::cout<<"If plus/minus"<<std::endl;
            token.type(Type::ADDOP);
            token.value(temp);
            tokens.push(token);
            temp="";
        }
    //Multiply or Divide
       else if (temp.compare("*")==0 || temp.compare("/")==0){
            //std::cout<<"If mult/div"<<std::endl;
            token.type(Type::MULTOP);
            token.value(temp);
            tokens.push(token);
            temp="";
        }

    //Fraction
       else if (temp.compare("F")==0 || temp.compare("f")==0){
        //std::cout<<"If fraction"<<std::endl;
            while (line.at(idx)!=')'){
                temp+=line.at(idx++);
            }
            token.type(Type::FRACTION);
            token.value(temp+')');
            tokens.push(token);
            temp="";
       }

    //Number
       else{
           //std::cout<<"Else number"<<std::endl;
            while(idx<line.length() && (line.at(idx)!=('+') || line.at(idx)!='-' || line.at(idx)!='*'
                  || line.at(idx)!='/' || line.at(idx)!=' ')){
                temp+=line.at(idx++);
            }
            token.type(Type::NUMBER);
            token.value(temp);
            tokens.push(token);
            temp="";
        }


/*
     if (line.at(idx)=='\0'){
         std::cout<<"if null character"<<std::endl;
            line="";
            idx=0;
            token.type(Type::EOL);
            token.value('\0');
        }
*/
    }
}


