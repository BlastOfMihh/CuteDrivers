//
// Created by mihh on 6/27/23.
//

#pragma once
#include "vector"
#include "string"

class Observer{
public :
    virtual void update()=0;
};

class Subject{
protected:
    std::vector<Observer*> observers;
public:
    void notify(){
        for(auto observer:observers){
            observer->update();
        }
    }
    void registerObserver(Observer * observer){
        observers.push_back(observer);
    }
    void unregisterObserver(Observer * observerOld){
        int i=0;
        for(auto observer:observers) {
            if (observerOld==observer)
                observers.erase(observers.begin()+i);
            ++i;
        }
    }
};