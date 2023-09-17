//
// Created by mihh on 6/27/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DriverWindow.h" resolved

#include "driverwindow.h"
#include "ui_DriverWindow.h"



DriverWindow::~DriverWindow() {
    delete ui;
}
