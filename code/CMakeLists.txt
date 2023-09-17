cmake_minimum_required(VERSION 3.25)
project(test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/usr/bin/qmake6")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(test main.cpp Driver.h Report.h Repo.h Service.h Observer.h driverwindow.cpp driverwindow.h DriverWindow.ui)
target_link_libraries(test
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

