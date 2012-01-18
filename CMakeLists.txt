cmake_minimum_required(VERSION 2.6)


project(BluetoothGUI)

find_package(wxWidgets REQUIRED)

include( "${wxWidgets_USE_FILE}" )
include( "include/" )
set(GUI
	src/gui/)
set(TARGET_DIR
	bin/)
set(TARGET
	${TARGET_DIR}bsms)
set(GUI_SRC 
	${GUI}Main.cpp
	${GUI}BlueFrame.cpp
	${GUI}BlueDevice.cpp
)
file(MAKE_DIRECTORY ${TARGET_DIR})			
add_executable(${TARGET} ${GUI_SRC})
set(CMAKE_CXX_FLAGS "-g -Wall")
target_link_libraries(${TARGET} ${wxWidgets_LIBRARIES})
