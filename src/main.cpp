#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cmath>

int main() {
    auto outputFileName = "output_image.ppm";
    const int imageWidth = 800;
    const int imageHeight = 600;

    remove(outputFileName);
    std::ofstream outputFile(outputFileName);

    outputFile << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for (int height = 0; height < imageHeight; height++) {
        for (int width = 0; width < imageWidth; width++) {
            double r = double(width) / ((double)imageWidth - 1);
            double g = double(height) / ((double)imageHeight - 1);
            double b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            outputFile << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    std::cout << "Hello World!\n";

    outputFile.close();
}
