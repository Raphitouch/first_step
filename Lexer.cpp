/*Lexer- lex function implemenataion:*/
#include "Lexer.h"
/*constructor that saves the file name in member:*/
Lexer::Lexer(string fileName) {
    this->fileName = fileName;
}
/*getter:*/
int Lexer::getNum() {
    return num;
}
/*return the string array with the commands:*/
string* Lexer::lex() {
    string* commands;
    string line;
    int index = 0;
    ifstream file(this->fileName);
    if(file.is_open()){
        //getting number of strings to be lexed:
        while(getline(file,line)){
            while(line.size() > 0){
                if(line[0] != ' '){
                    if(line.find(" ") == string::npos){
                        index++;
                        break;
                    }
                    else{
                        line = line.substr(line.find(" "));
                        index++;
                    }
                }
                else{
                    if(line.size() == 1)
                        break;
                    line = line.substr(1);
                }
            }
        }
        //rewind file:
        file.clear();
        file.seekg(0);
        commands = new string[index];
        index = 0;
        //putting the commands in the new string array:
        while(getline(file,line)){
            while(line.size() > 0){
                if(line[0] != ' '){
                    if(line.find(" ") == string::npos){
                        commands[index] = line;
                        index++;
                        break;
                    }
                    else{
                        commands[index] = line.substr(0,line.find(" "));
                        line = line.substr(line.find(" "));
                        index++;
                    }
                }
                else{
                    if(line.size() == 1)
                        break;
                    line = line.substr(1);
                }
            }
        }
        this->num = index;
        file.close();
    }
    else throw invalid_argument("File cannot be opened!");
    return commands;
}