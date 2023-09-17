//
// Created by mihh on 6/27/23.
//

#pragma once
#include "vector"
#include "fstream"
#include "string"

template<class T>
class Repo{
    std::vector<T> data;
    std::string fileName;
    void load(){
        std::ifstream fin(fileName.c_str());
        std::string line;
        while(std::getline(fin, line)){
            data.push_back(T(line));
        }
    }
    void unLoad(){
        std::ofstream fout(fileName.c_str());
        for (auto &elem:data){
            fout << elem.str();
        }
    }
public:
    Repo(std::string fileName_) : fileName(fileName_){
        load();
    }
    std::vector<T> & getAll(){
        return data;
    }
    ~Repo(){
        unLoad();
    }
};