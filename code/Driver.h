//
// Created by mihh on 6/27/23.
//

#pragma once

#include "string"
#include "cmath"
#include "cstring"
#include "memory"
#include "vector"


class Driver{
    std::string name ;
    int x, y;
    int score=0;
public:
    Driver(std::string str){
        char *cStr= strdup(str.c_str());
        std::vector<std::string> tokens;
        for (char *p=strtok(cStr, ","); p; p=strtok(0, ",")){
            tokens.push_back(p);
        }
        free(cStr);
        name=tokens[0];
        x=std::stoi(tokens[1]);
        y=std::stoi(tokens[2]);
        score=std::stoi(tokens[3]);
    }
    std::string getName(){
        return name;
    }
    std::pair<int,int> getLocation(){
        return {x, y};
    }
    void setLocation(int x_, int y_){
        x=x_;
        y=y_;
    }
    int getScore(){
        return score;
    }
    void setScore(int x){
        score=x;
    }
    std::string str(){
        return name+","+std::to_string(x)+","+std::to_string(y)+","+std::to_string(score)+"\n";
    }
    double distance(std::pair<int,int> d1, std::pair<int,int> d2){
        return sqrt(pow(1.0*d1.first-d2.first, 2)+pow(1.0*d2.second-d2.second, 2));
    }
};

