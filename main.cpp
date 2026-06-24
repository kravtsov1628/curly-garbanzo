#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat src = cv::imread("../input.jpg");

    if (src.empty()) {
        src = cv::imread("input.jpg");
    }

    if (src.empty()) {
        std::cerr << "Error: Image not found in root or build folder!" << std::endl;
        return -1;
    }

    int x, y, width, height;

    std::cout << "Enter x coordinate: ";
    std::cin >> x;

    std::cout << "Enter y coordinate: ";
    std::cin >> y;

    std::cout << "Enter crop width: ";
    std::cin >> width;

    std::cout << "Enter crop height: ";
    std::cin >> height;

    if (x < 0 || y < 0 ||
        width <= 0 || height <= 0 ||
        x + width > src.cols ||
        y + height > src.rows) {

        std::cerr << "Error: Crop area is outside image boundaries!" << std::endl;
        return -1;
    }

    cv::Rect roi(x, y, width, height);
    cv::Mat cropped = src(roi);

    cv::imshow("Original", src);
    cv::imshow("Cropped", cropped);

    cv::waitKey(0);
    return 0;
}