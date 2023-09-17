//
// Created by mihh on 6/27/23.
//

#ifndef TEST_REPORT_H
#define TEST_REPORT_H
#include "cstring"
#include "string"
#include "vector"



class Report{
    std::string description, reporter;
    int x, y;
    bool valid=false;
    int validations=0;
public:
    Report(std::string str){
        char *cStr= strdup(str.c_str());
        std::vector<std::string> tokens;
        for (char *p=strtok(cStr, ","); p; p=strtok(0, ",")){
            tokens.push_back(p);
        }
        free(cStr);
        description=tokens[0];
        reporter=tokens[1];
        x=std::stoi(tokens[2]);
        y=std::stoi(tokens[3]);
        valid=std::stoi(tokens[4]);
    }
    std::pair<int,int> getLocation(){
        return {x, y};
    }
    void setLocation(int x_, int y_){
        x=x_;
        y=y_;
    }
    std::string str(){
        return description+","+reporter+","+std::to_string(x)+","+std::to_string(y)+","+std::to_string(int(valid))+"\n";
    }
    bool validate(){
        validations+=1;
        if (validations>=2)
            valid=true;
        return valid;
    }
    bool getValid(){
        return valid;
    }
    std::string getName(){
        return reporter;
    }
};
#endif //TEST_REPORT_H
