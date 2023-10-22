#include <iostream>
#include "../header/media.h"

Student::Student() : grades_({}), studentName_(" ") {}

// Limpa a tela 
void ScreenManager::clearScreen() const {
    std::system("cls");
}

// Limpa a tela herdada da classe ScreenManager
void Student::clearScreen() const {
    std::system("cls");
}

// Pergunta o nome do aluno
void Student::askStudentName() {
    std::vector<std::size_t> keepSpace;
    char opc;

    while(true) {
        std::cout << "Digite o nome do aluno(a): ";
        std::getline(std::cin, studentName_);

        for(auto i = 0; i < studentName_.length(); i++) {
            if(studentName_[i] == ' ') {
                keepSpace.push_back(i);
            }
        }

        bool isString {true};
        studentName_.erase(std::remove(studentName_.begin(), studentName_.end(), ' '), studentName_.end());
        for(char & i : studentName_) {
            if(!isalpha(i)) {
                isString = false;
            }
        }

        if(isString && !studentName_.empty()) {
            for(auto i : keepSpace) {
                studentName_.insert(i, " ");
            }
            studentName_[0] = std::toupper(studentName_[0]);
        }

        else {
            std::cout << "INVALIDO! Nao coloque numeros e caracteres no nome ou deixe o campo vazio." << '\n'; 
            std::cout << "Aperte Enter para continuar...";
            std::cin.get();
            studentName_.clear();
            keepSpace.clear();
            clearScreen();
            continue;
        }

        if(studentName_.length() < 2) {
            std::cout << "INVALIDO! Nome Pequeno demais." << '\n';
            std::cout << "Aperte Enter para continuar...";
            std::cin.get();
            studentName_.clear();
            keepSpace.clear();
            clearScreen();
            continue;
        }

        std::cout << "O nome do aluno e: " << studentName_ << " esta correto? sim(s)/nao(n): ";
        std::cin >> opc;
        std::cin.ignore();

        if(opc == 's' || opc == 'S') {
            break;
        }

        else {
            studentName_.clear();
            keepSpace.clear();
            clearScreen();
            continue;
        }
    }
}

void Student::calculateGrades() {
    std::size_t subjects;
    int indice = 0;

    while(true) {
        std::cout << "Quantas materias sao: ";
        std::cin >> subjects;

        for(auto i = 0; i < subjects; i++) {
            std::cout << "Digite a " << ++indice << " nota: " << '\n';
            std::cin >> grade_;
            grades_.push_back(grade_);
        }

        break;
    }
}

// Obtem o nome do aluno
std::string Student::getStudentName() const {
    return studentName_;
}

std::vector<double> Student::getGrades() const {
    return grades_;
}

// Mostra os dados do aluno na tela
void Display::displayStudent(Student & obj) {
    obj.askStudentName();
    obj.calculateGrades();
    obj.clearScreen();
    std::cout << obj.getStudentName() << '\n';
    for(auto i : obj.getGrades()) {
        std::cout << i << '\n';
    }
    
}