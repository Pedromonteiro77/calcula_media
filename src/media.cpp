#include <iostream>
#include "../header/media.h"

// Construtor da classe ScreenManager
ScreenManager::ScreenManager() {}

// Destrutor da classe ScreenManager
ScreenManager::~ScreenManager() {}

// Limpa a tela 
void ScreenManager::clearScreen() const {
    std::system("cls");
}

/////////////////////////////////////////////

// Construtor da classe Student
Student::Student() : grades_({}), studentName_(" ") {}

// Destrutor da classe Student
Student::~Student() {}

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

// Calcula as notas do aluno
void Student::calculateGrades() {
    std::size_t subjects;
    char opc;

    while(true) {
        int indice = 0;
        std::string input;

        std::cout << "Quantas materias sao: ";
        std::cin >> input;

        bool isDigit = true;
        for(auto i : input) {
            if(!isdigit(i)) {
                isDigit = false;
                break;
            }
        }

        if(!isDigit) {
            std::cout << "INVALIDO! Nao digite letras ou simbolos" << '\n';
            std::cout << "Aperte Enter para continuar...";
            std::cin.get();
            std::cin.ignore();
            input.clear();
            continue;
        }

        subjects = std::stoul(input);

        if(subjects == 0 || subjects > 5) {
            std::cout << "INVALIDO! o numero de materias não pode ser 0 ou maior que 5!" << '\n';
            std::cout << "Aperte Enter para continuar...";
            std::cin.get();
            std::cin.ignore();
            continue;
        }

        for(auto i = 0; i < subjects; i++) {
            std::cout << "Digite a " << ++indice << " nota: " << '\n';
            std::cin >> grade_;
            grades_.push_back(grade_);
        }

        std::cout << "As notas do aluno sao: " << '\n';
        for(auto i : grades_) {
            std::cout << i << '\n';
        }

        std::cout << "Voce confirma? sim(s)/nao(n): ";
        std::cin >> opc;
        std::cin.ignore();

        if(opc == 's' || opc == 'S') {
            break;
        }

        else {
            grades_.clear();
            continue;
        }
    }
}

// Obtem o nome do aluno
std::string Student::getStudentName() const {
    return studentName_;
}

std::vector<double> Student::getGrades() const {
    return grades_;
}

////////////////////////////////////////////////////////

// Construtor da classe Display 
Display::Display(std::unique_ptr<Student> obj) : obj_(std::move(obj)) {}

// Destrutor da classe Display
Display::~Display() {}

// Mostra os dados do aluno na tela
void Display::displayStudent() {
    obj_->askStudentName();
    obj_->calculateGrades();
    obj_->clearScreen();
    std::cout << obj_->getStudentName() << '\n';
    for(auto i : obj_->getGrades()) {
        std::cout << i << '\n';
    }  
}