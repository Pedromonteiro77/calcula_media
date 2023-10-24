#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cstddef>
#include <memory>
#include <utility>
#include "../header/media.h"

int main() {
    ScreenManager objScreen; // Objeto que configura o que acontece na tela
    std::unique_ptr<Student> ptrStudent = std::make_unique<Student>(); // Objeto que configura os metodos da classe student
    Display student {std::move(ptrStudent)};    // Objeto que Mostra as informações do estudante

    objScreen.clearScreen();  
    student.displayStudent();

    return 0;
}