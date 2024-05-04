#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>

char brightness_to_ascii (int brightness) {
    switch (brightness)
    {
    case 0 ... 32:
        return ' ';
        break;
    case 33 ... 64:
        return '.';
        break;
    case 65 ... 97:
        return ',';
        break;
    case 98 ... 130:
        return ':';
        break;
    case 131 ... 163:
        return 'i';
        break;
    case 164 ... 196:
        return 'l';
        break;
    case 197 ... 229:
        return 'w';
        break;
    case 230 ... 255:
        return 'W';
        break;
    default:
        break;
    }
    return NULL;
}

char brightness_to_ascii_v2(int brightness) {
    const char *ascii_chars = "`.-':_,^=;><+!rc*/z?sLTv)J7(|Fi{C}fI31tlu2ESwqkP6h9d4VpOGbUAKXHm8RD#$Bg0MNWQ%&@";

    int index = (brightness * (sizeof(ascii_chars) - 2)) / 255;

    return ascii_chars[index];
}

int main() {
    cv::Mat image = cv::imread("img6.jpg", cv::IMREAD_GRAYSCALE); 
    cv::resize(image, image, cv::Size(), 1, 1);

    if (image.empty()) {
        std::cout << "Não foi possível abrir a imagem." << std::endl;
        return -1;
    }

    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        std::cout << "Não foi possível abrir o arquivo de saída." << std::endl;
        return -1;
    }

    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            uchar intensity = image.at<uchar>(i, j);
            char ascii_char = brightness_to_ascii((int)intensity);
            outputFile << ascii_char;
        }
        outputFile << '\n'; 
    }
    outputFile.close();

    return 0;
}
