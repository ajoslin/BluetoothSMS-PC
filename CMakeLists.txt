cmake_minimum_required(VERSION 2.6)


project(BluetoothGUI)

find_package(wxWidgets REQUIRED)

include( "${wxWidgets_USE_FILE}" )
include_directories( "include/" )
set(GUI
	src/gui/)
set(SMS
	src/)
set(TARGET_DIR
	bin/)
set(TARGET
	${TARGET_DIR}bsms)
set(GUI_SRC 
	${GUI}ContactsListBox.cpp
	${GUI}DeviceDialog.cpp
	${GUI}DevicePanel.cpp
	${GUI}MainApp.cpp
	${GUI}MainFrame.cpp
	${GUI}MessagePanel.cpp
	${GUI}MessageThreadsPanel.cpp
	)
set(SMS_SRC
	${SMS}Contact.cpp
	${SMS}Message.cpp
	${SMS}MessageThread.cpp
	${SMS}ContactContainer.cpp)
	
file(MAKE_DIRECTORY ${TARGET_DIR})			
add_executable(${TARGET} ${GUI_SRC} ${SMS_SRC})
set(CMAKE_CXX_FLAGS "-g -Wall")
target_link_libraries(${TARGET} ${wxWidgets_LIBRARIES})
