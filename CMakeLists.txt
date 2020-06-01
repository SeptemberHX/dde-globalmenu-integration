cmake_minimum_required(VERSION 3.13)

#configure_file(config-X11.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config-X11.h)

set(PROJECT dde-globalmenu-theme)

project(${PROJECT})

remove_definitions(-DQT_NO_CAST_FROM_ASCII -DQT_STRICT_ITERATORS -DQT_NO_CAST_FROM_BYTEARRAY -DQT_NO_KEYWORDS)

set(CMAKE_CXX_STANDARD 14)

# 启用 qt moc 的支持
set(CMAKE_AUTOMOC ON)
# 启用 qrc 资源文件的支持
set(CMAKE_AUTORCC ON)

set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5DBus REQUIRED)
find_package(X11)
find_package(Qt5 CONFIG REQUIRED X11Extras)
find_package(KF5WindowSystem REQUIRED)


set(SRCS ddeglobalmenutheme.cpp ddeglobalmenutheme.h
        qdbusmenubar_p.h qdbusmenubar.cpp
        config-X11.h
        )


add_library(${PROJECT} MODULE ${SRCS})

target_include_directories(${PROJECT} PUBLIC
        ${Qt5Widgets_INCLUDE_DIRS}
        ${Qt5DBus_INCLUDE_DIRS}
        )

target_link_libraries(${PROJECT} PRIVATE Qt5::X11Extras
        Qt5::Widgets
        Qt5::DBus
        KF5::WindowSystem
        )