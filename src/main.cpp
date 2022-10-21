#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cmath>
#include "ray.hpp"
#include "color.hpp"
#include "objects/sphere.hpp"
#include "math/vector3d.hpp"
#include "math/utils.hpp"

class LightSource {
public:
    LightSource(const Point3d& origin, double intensity)
        : m_origin(origin), m_intensity(intensity) {}

    Point3d Origin() const { return m_origin; }
    double Intensity() const { return m_intensity; }


private:
    Point3d m_origin;
    double m_intensity;
};


void outputPixel(std::ostream& out, Color pixelColor) {
    out << static_cast<int>(255.999 * pixelColor.R) << ' '
        << static_cast<int>(255.999 * pixelColor.G) << ' '
        << static_cast<int>(255.999 * pixelColor.B) << '\n';
}

Color castRay(const Ray& ray, const Sphere& sphere, const Sphere& sphere2, const LightSource& light) {

    //auto normalizedDirection = ray.Direction().Normalized();
    //auto tt = 0.5 * (normalizedDirection.Y() + 3.0);

    IntersectionResult intersectionResult;
    if (sphere.Intersect(ray, intersectionResult)) {
        if (intersectionResult.Distance > 0) {
            auto color = Vector3d(0.5, 0.5, 0);

            double diffuse_light_intensity = 0;
   
            auto light_dir = (light.Origin() - intersectionResult.HitPoint).Normalized();
            diffuse_light_intensity += light.Intensity() * std::max(0.0, light_dir.DotProduct(intersectionResult.Normal));

            auto resultColor = color * diffuse_light_intensity;
            return Color(resultColor.X(), resultColor.Y(), resultColor.Z());


            auto n = (ray.AtDistance(intersectionResult.Distance) - Vector3d(0, 0, -1)).Normalized();
            auto res = 0.5 * Vector3d(n.X() + 1, n.Y() + 1, n.Z() + 1);
            return Color(res.X(), res.Y(), res.Z());
        }
        return Color(1, 0, 0);
    }

    IntersectionResult intersectionResult2;
    if (sphere2.Intersect(ray, intersectionResult2)) {
        if (intersectionResult2.Distance > 0) {
            auto color = Vector3d(0.5, 0.2, 0);

            double diffuse_light_intensity = 0;

            auto light_dir = (light.Origin() - intersectionResult2.HitPoint).Normalized();
            diffuse_light_intensity += light.Intensity() * std::max(0.0, light_dir.DotProduct(intersectionResult2.Normal));

            auto resultColor = color * diffuse_light_intensity;
            return Color(resultColor.X(), resultColor.Y(), resultColor.Z());

            auto n = (ray.AtDistance(intersectionResult2.Distance) - Vector3d(0, 0, -1)).Normalized();
            auto res = 0.5 * Vector3d(n.X() + 1, n.Y() + 1, n.Z() + 1);
            return Color(res.X(), res.Y(), res.Z());
        }
        return Color(0, 1, 0);
    }

    const auto whiteColor = ColorRGB(1, 1, 1);
    const auto lightBlueColor = ColorRGB(0.5, 0.7, 1);

    auto normalizedValue = normalizeToUnitInterval(ray.Direction().Y(), -2, 2);
    auto result = whiteColor * (1.0 - normalizedValue) + lightBlueColor * normalizedValue;
    return Color(result.X(), result.Y(), result.Z());
}

int main() {
    auto outputFileName = "output_image.ppm";
    remove(outputFileName);
    std::ofstream outputFile(outputFileName);

    const int imageWidth = 800;
    const int imageHeight = 600;

    const auto cameraLocation = Point3d();
    const auto screenTopLeftLocation = Point3d(-3, 2, -1);
    const auto screenWidth = 6.0;
    const auto screenHeight = 4.0;

    const auto screenTopRightLocation = screenTopLeftLocation + Point3d(screenWidth, 0, 0);
    const auto screenBotLeftLocation = screenTopLeftLocation + Point3d(0, -screenHeight, 0);

    const auto sphere = Sphere(Point3d(2.5, 0, -8), 3);
    const auto sphere2 = Sphere(Point3d(-2.5, 0, -10), 5);

    const auto light = LightSource(Point3d(-10, 10, 20), 1.1);

    outputFile << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for (int height = 0; height < imageHeight; height++) {
        //std::cout << "Lines painted: " << height << std::endl;
        for (int width = 0; width < imageWidth; width++) {
            //double r = double(width) / ((double)imageWidth - 1);
            //double g = double(height) / ((double)imageHeight - 1);
            //double b = 0.25;
            //Color pixelColor(r, g, b);

            double relativeWidth = double(width) / ((double)imageWidth - 1);
            double relativeHeight = double(height) / ((double)imageHeight - 1);

            Ray ray(cameraLocation,
                screenBotLeftLocation
                + ((screenTopRightLocation - screenTopLeftLocation) * relativeWidth)
                + ((screenTopLeftLocation - screenBotLeftLocation) * relativeHeight));

            Ray ray3(cameraLocation,
                screenBotLeftLocation
                + (Point3d(screenWidth, 0, 0) * relativeWidth)
                + (Point3d(0, screenHeight, 0) * relativeHeight));

            Color pixelColor = castRay(ray3, sphere, sphere2, light);

            outputPixel(outputFile, pixelColor);
        }
    }

    std::cout << "Hello World!\n";

    outputFile.close();
}
