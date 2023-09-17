//
// Created by mihh on 6/27/23.
//

#ifndef TEST_DRIVERWINDOW_H
#define TEST_DRIVERWINDOW_H

#include "QPainter"
#include "QMessageBox"
#include <QWidget>
#include "ui_DriverWindow.h"
#include "Driver.h"
#include "Observer.h"
#include "Service.h"

class reportmap : public QWidget {
Q_OBJECT
private:
    Service * service;
public:
    explicit reportmap(Service *service_, QWidget *parent = nullptr) : QWidget(parent), service(service_){
        paintEvent(0);
        //RenderArea
    }

    void paintEvent(QPaintEvent *){
        //shapeComboBox = new QComboBox
        for (auto &report:service->getReports()){
            //paint->drawEllipse(report.getLocation().first, report.getLocation().second, 1, 2);
            //map->paint
            //new QLabel(this).pos;
            auto paint = new QPainter(this);
            paint->setPen(Qt::blue);
            paint->setFont(QFont("Arial", 30));
            paint->drawEllipse(report.getLocation().first*100, report.getLocation().second*100, 15, 15);
            ///paint->drawText(rect(), Qt::AlignCenter, "Qt");
        }
    }

};

QT_BEGIN_NAMESPACE
namespace Ui { class DriverWindow; }
QT_END_NAMESPACE

class DriverWindow : public QWidget , public Observer{
Q_OBJECT

private:
    Ui::DriverWindow *ui;
    Service * service;
    Driver & driver;

public:
    void updScores(){
        ui->scoreLabel->setText("Score"+QString::number(driver.getScore()));
        ui->locationLabel->setText("Location:"+ QString::number(driver.getLocation().first) +","+ QString::number(driver.getLocation().second));
    }

    explicit DriverWindow(Driver& driver, Service* service_, QWidget *parent = nullptr):
                QWidget(parent), ui(new Ui::DriverWindow) , service(service_), driver(driver){
        ui->setupUi(this);
        updScores();
        showReports();
        connect(ui->chatButton, SIGNAL(pressed()), this, SLOT(sendChat()));
        connect(ui->fileReportB, SIGNAL(pressed()), this, SLOT(sendReport()));
        connect(ui->validateReportButton, SIGNAL(pressed()), this, SLOT(validateReport()));
        connect(ui->showMapButton, SIGNAL(pressed()), this, SLOT(showMap()));
    }

    void showReports(){
        ui->listReports->clear();
        int i=0;
        for (auto report:service->getReports()){
            if (driver.distance(driver.getLocation(), report.getLocation())<=10.0){
                ui->listReports->addItem(QString::fromStdString(report.str()));
                if (report.getValid()){
                    const auto &thisItem=ui->listReports->item(i);
                    thisItem->font().setWeight(QFont::Weight::Bold);
                    thisItem->setBackground(Qt::red);
                    thisItem->font().setBold(true);
                    //thisItem->setFont(QFont("Jetbrains Mono", QFont::Weight::Bold));
                    auto font= thisItem->font();
                    font.setBold(true);
                    font.setUnderline(true);
                    thisItem->setFont(font);
                }
                ++i;
            }
        }
    }

    void showChat(){
        ui->chatList->clear();
        for (auto msg:service->getMessages()){
            ui->chatList->addItem(QString::fromStdString(msg));
        }
    }

public slots:

    void sendReport(){
        std::string description=ui->reportDescriptionLine->text().toStdString();
        int x=ui->reportLineX->text().toInt();
        int y=ui->reportLineY->text().toInt();
        if (driver.distance(driver.getLocation(), std::make_pair(x,y))>20 or description.size()==0){
            auto msg=new QMessageBox();
            msg->setText("not good");
            (msg)->show();
        }else{
            service->addReport(description,driver.getName(), x,y, 0);
            showReports();
        }
    };

    void sendChat(){
        QString qstr =ui->chatLine->text();
        std::string message= qstr.toStdString(); // ui->chatLine->text().toStdString();
        if (message.size()==0) {
            return;
        }
        message = driver.getName()+":"+message;
        service->addMessage(message);
        service->notify();
    }

    void validateReport(){
        //try{
        auto curr=ui->listReports->currentItem()->text().toStdString();
        service->validateReport(curr,driver);
        showReports();
        service->notify();
        //}catch(const std::exception & e){

        //}
    }
    void showMap(){
        auto map=new reportmap(service);
        for (auto &report:service->getReports()){
            //paint->drawEllipse(report.getLocation().first, report.getLocation().second, 1, 2);
            //map->paint
        }
        map->show();
        map->setWindowTitle("Map");
        map->repaint();
    }
public:

    void update() override{
        showChat();
        updScores();
    }

    ~DriverWindow() override;
};


#endif //TEST_DRIVERWINDOW_H
