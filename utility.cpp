#pragma once
#include "raylib.h"
#include <vector>
#include <iostream>

namespace utility {
    template <typename T>
    void print_vector(const std::vector<T>& vectorObject, const std::string& label = "Vector") {
        std::cout << label << ": [";
        for (size_t i = 0; i < vectorObject.size(); ++i) {
            std::cout << vectorObject[i];
            if (i < vectorObject.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
}