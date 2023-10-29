#include <iostream>
#include "../header/media.h"

ScreenManager::ScreenManager() {}

ScreenManager::~ScreenManager() {}

void ScreenManager::clearScreen() const {
    std::system("cls");
}

Student::Student() : grades_({}), studentName_(" "), grade_(0.0), average_(0.0) {}

Student::~Student() {}

void Student::clearScreen() const {
    std::system("cls");
}

void Student::askStudentName() {
    std::vector<std::size_t> keepSpace;
    char opc;

    while(true) {
        try {
            std::cout << "Digite o nome do aluno: ";
            std::getline(std::cin, studentName_);

            if(studentName_.empty()) {
                throw std::invalid_argument("INVALIDO! Nao deixe o campo vazio.");
            }

            for(auto i = 0; i < studentName_.length(); ++i) {
                if(studentName_[i] == ' ') {
                    keepSpace.push_back(i);
                }
            }

            bool isAlpha {true};
            studentName_.erase(std::remove(studentName_.begin(), studentName_.end(), ' '), studentName_.end());
            for(char & i : studentName_) {
                if(!std::isalpha(i)) {
                    isAlpha = false;
                    break;
                }
            }
            
            if(!isAlpha) {
                throw std::invalid_argument("INVALIDO! O nome nao pode ter numeros ou caracteres.");
            }

            for(auto i : keepSpace) {
                studentName_.insert(i, " ");
            }

            if(studentName_.length() < 2) {
                throw std::invalid_argument("INVALIDO! Nome curto demais.");
            }

            std::cout << "O nome do aluno e: " << studentName_ << " correto? sim(s)/nao(n): ";
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

        catch(const std::invalid_argument & e) {
            std::cerr << e.what() << '\n';
            std::cout << "Aperte enter para continuar...";
            std::cin.get();
            studentName_.clear();
            keepSpace.clear();
            clearScreen();
            continue;
        }
    }
    clearScreen();
}

void Student::calculateGrades() {
    std::size_t subjects;
    char opc;

    while(true) {
        int indice = 0;
        std::string input;

        std::cout << "Quantas materias sao: ";
        std::getline(std::cin, input);

        if(input.empty() || !std::all_of(input.begin(), input.end(), ::isdigit)) {
            std::cout << "INVALIDO! Insira um valor numerico valido." << '\n';
            std::cout << "Aperte Enter para continuar...";
            std::cin.get();
            input.clear();
            clearScreen();
            continue;
        }

        subjects = std::stoul(input);

        if(subjects == 0 || subjects > 5) {
            std::cout << "INVALIDO! o numero de materias não pode ser 0 ou maior que 5!" << '\n';
            std::cout << "Aperte Enter para continuar...";
            std::cin.get();
            clearScreen();
            continue;
        }

        clearScreen();
        
        size_t i = 0;
        while(i < subjects) {
            std::string strGrade;
            std::cout << "Digite a " << ++indice << " nota: ";
            std::getline(std::cin, strGrade);

            bool digit {true};
            for(char & c : strGrade) {
                if(!std::isdigit(c) && c != '.' && c != '-') {
                    digit = false;
                    break;
                }
            }

            if(strGrade.empty()) {
                std::cout << "INVALIDO! Nao deixe o campo vazio" << '\n';
                std::cout << "Aperte Enter para continuar...";
                std::cin.get();
                strGrade.clear();
                --indice;
                clearScreen();
                continue;
            }

            if(!digit) {
                std::cout << "INVALIDO! Nao digite letras ou simbolos" << '\n';
                std::cout << "Aperte Enter para continuar...";
                std::cin.get();
                strGrade.clear();
                --indice;
                clearScreen();
                continue;
            }

            try {
                grade_ = std::stof(strGrade);
                if(grade_ > 10.0 || grade_ < 0.0) {
                    std::cout << "INVALIDO! A nota deve estar entre 0 e 10" << '\n';
                    std::cout << "Aperte Enter para continuar...";
                    std::cin.get();
                    strGrade.clear();
                    --indice;
                    clearScreen();
                    continue;
                }
                grades_.push_back(grade_);
                i++;
            }            
            catch (const std::invalid_argument & e) {
                std::cout << "INVALIDO! Entrada inválida para um número" << '\n';
                std::cout << "Aperte Enter para continuar...";
                std::cin.get();
                strGrade.clear();
                --indice;
                clearScreen();
                continue;
            }
        }

        std::cout << "As notas do aluno sao: " << '\n';
        for(auto i : grades_) {
            std::cout << std::fixed << std::setprecision(1) << i << '\n';
        }

        std::cout << "Voce confirma? sim(s)/nao(n): ";
        std::cin >> opc;
        std::cin.ignore();

        float sum = 0.0f;
        if(opc == 's' || opc == 'S') {
            for(auto & i : grades_) {
                sum += i;
            }
            average_ = sum / subjects;
            break; 
        }

        else {
            grades_.clear();
            clearScreen();
            continue;
        }
    }
}

std::string Student::getStudentName() const {
    return studentName_;
}

float Student::getAverage() const {
    return average_;
}

Display::Display(std::unique_ptr<Student> obj) : obj_(std::move(obj)) {}

Display::~Display() {}

void Display::displayStudent() {
    obj_->askStudentName();
    obj_->calculateGrades();
    obj_->clearScreen();
    std::cout << "A media do aluno " << obj_->getStudentName() << " e: "; 
    std::cout << std::fixed << std::setprecision(1) << obj_->getAverage() << '\n';

    if(obj_->getAverage() >= 7) {
        std::cout << "O aluno(a) esta APROVADO";
    }

    else if(obj_->getAverage() >= 5.0 && obj_->getAverage() <= 6.9) {
        std::cout << "O aluno(a) esta de RECUPERACAO";
    }

    else if(obj_->getAverage() < 5.0) {
        std::cout << "O aluno(a) foi REPROVADO";
    }
}