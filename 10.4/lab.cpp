#include <iostream>
#include <fstream>
#include <cmath>

struct Point {
    double x;
    double y;
};

enum TriangleType {
    Equilateral,
    Isosceles,
    Scalene,
    RightAngled,
    Unknown
};

// Function to calculate distance between two points
double calculateDistance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to determine the type of triangle
TriangleType determineTriangleType(double a, double b, double c) {
    if (a == b && b == c) {
        return Equilateral;
    }
    else if (a == b || b == c || a == c) {
        return Isosceles;
    }
    else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
        return RightAngled;
    }
    else {
        return Scalene;
    }
}

// Function to read triangle coordinates from a file
bool readTriangleFromFile(const std::string& fileName, Point& p1, Point& p2, Point& p3) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return false;
    }

    file >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

    file.close();
    return true;
}

// Function to write triangle type to a file
void writeTriangleTypeToFile(const std::string& fileName, TriangleType type) {
    std::ofstream file(fileName, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    switch (type) {
    case Equilateral:
        file << "Equilateral" << std::endl;
        break;
    case Isosceles:
        file << "Isosceles" << std::endl;
        break;
    case Scalene:
        file << "Scalene" << std::endl;
        break;
    case RightAngled:
        file << "Right-Angled" << std::endl;
        break;
    case Unknown:
        file << "Unknown" << std::endl;
        break;
    }

    file.close();
}

int main() {
    Point p1, p2, p3;

    std::cout << "Enter the input file name: ";
    std::string inputFileName;
    std::cin >> inputFileName;

    if (!readTriangleFromFile(inputFileName, p1, p2, p3)) {
        return 1;
    }

    double side1 = calculateDistance(p1, p2);
    double side2 = calculateDistance(p2, p3);
    double side3 = calculateDistance(p3, p1);

    TriangleType triangleType = determineTriangleType(side1, side2, side3);

    std::cout << "Type of the triangle: ";
    switch (triangleType) {
    case Equilateral:
        std::cout << "Equilateral" << std::endl;
        break;
    case Isosceles:
        std::cout << "Isosceles" << std::endl;
        break;
    case Scalene:
        std::cout << "Scalene" << std::endl;
        break;
    case RightAngled:
        std::cout << "Right-Angled" << std::endl;
        break;
    case Unknown:
        std::cout << "Unknown" << std::endl;
        break;
    }

    std::cout << "Enter the output file name: ";
    std::string outputFileName;
    std::cin >> outputFileName;

    writeTriangleTypeToFile(outputFileName, triangleType);

    return 0;
}
