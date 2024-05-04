# Transforming Images to Text Using OpenCV in C++

## Description

This simple C++ code utilizes the OpenCV library to convert images to a text file. It iterates through each pixel of the image and converts it to a character based on its brightness level ranging from 0 to 255.

## Prerequisites

- OpenCV 2 library installed
- Basic knowledge of C++ programming

## Usage

1. Ensure OpenCV is properly installed on your system.
2. Compile the C++ code using a C++ compiler like g++.
3. The program will process the image and generate a text file containing the ASCII representation of the image.

## Running the Code

1. Compile the code using a C++ compiler (or just use make):

```Terminal
g++ -std=c++14 -Wall -I/usr/include/opencv4 main.cpp -o main -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs
```

2. Run

```Terminal
./main
```

3. Open the output.txt file with a text editor.
