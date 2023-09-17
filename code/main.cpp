#include <QApplication>
#include <QPushButton>
#include "Service.h"
#include "Repo.h"
#include "driverwindow.h"
#include "iostream"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    auto driversRepo=new Repo<Driver>("d.in");
    auto reportsRepo=new Repo<Report>("r.in");
    auto service=new Service(driversRepo, reportsRepo);

    for (auto &driver:service->getDrivers()){
        auto d1=new DriverWindow(driver, service);
        d1->setWindowTitle(QString::fromStdString(driver.getName()));
        service->registerObserver(d1);
        d1->show();
    }

    int ret=QApplication::exec();
    delete service;
    delete driversRepo;
    delete reportsRepo;
    return ret;
}
