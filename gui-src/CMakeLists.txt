cmake_minimum_required(VERSION 2.6)


project(BluetoothGUI)

find_package(wxWidgets REQUIRED)

include( "${wxWidgets_USE_FILE}" )

set(GUI_SRC 
	Main.cpp
	BlueFrame.cpp
	BlueDevice.cpp
)
			
add_executable(BluetoothGUI ${GUI_SRC})

target_link_libraries(BluetoothGUI ${wxWidgets_LIBRARIES})