cmake_minimum_required(VERSION 3.0.0) 
project (networkchat)
SET(CMAKE_BUILD_TYPE Debug) 



SET(CMAKE_CXX_FILES "-g -Wall") 
message("Debug mode") 

#find QT libraries 

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5WebChannel REQUIRED)
find_package(Qt5WebSockets REQUIRED) 

# Instruct CMake to run moc automatically when needed. 
set(CMAKE_AUTOMOC ON) 
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# As moc files are generated in the binary dir, tell CMake 
# to always look for includes there: 
set(CMAKE_INCLUDE_CURRENT_DIR ON) 
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_BINARY_DIR} ) 
# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5. 
add_definitions(${Qt5Widgets_DEFINITIONS}) 



SET(SRC 
network-chat/connection.cpp 
network-chat/chatdialog.cpp 
network-chat/peermanager.cpp
network-chat/client.cpp
network-chat/server.cpp
network-chat/main.cpp 
network-chat/connection.h 
network-chat/chatdialog.h 
network-chat/peermanager.h
network-chat/client.h
network-chat/server.h
) 


QT5_WRAP_UI(UIS_HDRS 
network-chat/chatdialog.ui 
) 




add_executable(network-chat ${SRC} ${UIS_HDRS} )
qt5_use_modules(network-chat Core Gui Widgets Network WebChannel WebSockets)
