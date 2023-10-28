#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cstddef>
#include <memory>
#include <utility>
#include <iomanip>
#include "../header/media.h"

int main() {
    ScreenManager objScreen; 
    std::unique_ptr<Student> ptrStudent = std::make_unique<Student>(); 
    Display student {std::move(ptrStudent)};

    objScreen.clearScreen();  
    student.displayStudent();

    return 0;
}