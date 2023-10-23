#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cstddef>
#include "../header/media.h"

int main() {
    ScreenManager objScreen; // Objeto que configura o que acontece na tela
    Student * objStudent = new Student;     // Objeto que configura os metodos da classe student
    Display student;       // Objeto que Mostra as informações do estudante

    objScreen.clearScreen();  
    student.displayStudent(objStudent);

    delete objStudent;

    return 0;
}