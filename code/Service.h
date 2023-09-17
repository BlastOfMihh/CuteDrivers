//
// Created by mihh on 6/27/23.
//

#pragma once

#include "iostream"
#include "vector"
#include "string"
#include "Repo.h"
#include "Driver.h"
#include "Report.h"
#include "Observer.h"


class Service : public Subject{
    Repo<Driver> *repoDriver;
    Repo<Report> *repoReport;
    std::vector<std::string> chat;

public:

    Service(Repo<Driver> *repoDriver_, Repo<Report> *repoReport_) {
        repoDriver = repoDriver_;
        repoReport = repoReport_;
    }

    std::vector<Driver> &getDrivers() {
        return repoDriver->getAll();
    }

    std::vector<Report> &getReports() {
        return repoReport->getAll();
    }

 //   void addDriver() {

 //   }

    void addReport(std::string description, std::string reporter, int x, int y, bool valid) {
        repoReport->getAll().push_back(
                description + "," + reporter + "," + std::to_string(x) + "," + std::to_string(y) + "," +
                std::to_string(int(valid)) + "\n");
    }

    void addMessage(std::string message){
        std::cerr<<message<<"\n";
        chat.push_back(message);
    }
    std::vector<std::string> & getMessages(){
        return chat;
    }
    bool validateReport(std::string matching, Driver & driver____){
        for (auto & report:getReports()){
            if (report.str()==matching and report.getValid()==false){
                report.validate();
                if (report.getValid()==true)
                    for (auto & driver:getDrivers()){
                        if (driver.getName()==report.getName()){
                            driver.setScore(driver.getScore()+1);
                            break;
                        }
                    }
                return report.getValid();
            }
        }
        return false;
    }
};
