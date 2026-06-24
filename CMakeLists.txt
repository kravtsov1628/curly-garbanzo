cmake_minimum_required(VERSION 3.5)
project(SepiaEffect)

set(OpenCV_DIR "C:/msys64/mingw64/lib/cmake/opencv4")

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(SepiaEffect main.cpp)

target_link_libraries(SepiaEffect opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)
