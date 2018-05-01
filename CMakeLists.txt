cmake_minimum_required(VERSION 2.8)

project(OpenGL)

set(HEADERS 
	include/OpenGL/Window/Window.h
	include/OpenGL/Object/Object.h
	include/OpenGL/Component/Component.h
	include/OpenGL/Helper/Helper.h
	include/OpenGL/Math/Math.h
	include/OpenGL/GLFunction/GLFunction.h
	include/OpenGL/Template/Template.h)
	
set(SOURCES 
	src/OpenGL/Window/Window.cpp
	src/OpenGL/Object/Object.cpp
	src/OpenGL/Component/Component.cpp
	src/OpenGL/Helper/Helper.cpp
	src/OpenGL/Math/Math.cpp
	src/OpenGL/GLFunction/GLFunction.cpp
	)	

include_directories(include
                    lib/glew-2.1.0/include
					lib/glfw-3.2.1.bin.WIN32/include)


find_library(GLFW
             NAMES glfw3.lib
			 PATHS ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw-3.2.1.bin.WIN32/lib-vc2015 )

find_library(GLEW 
             NAMES glew32.lib
			 PATHS ${CMAKE_CURRENT_SOURCE_DIR}/lib/glew-2.1.0/lib/Release/Win32 )

add_executable(OpenGL src/Main.cpp ${SOURCES} ${HEADERS})

target_link_libraries(OpenGL opengl32.lib ${GLFW} ${GLEW})
