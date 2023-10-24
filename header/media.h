#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cstddef>
#include <memory>
#include <utility>

class ScreenManager {                      // Classe que gerencia a tela
public:
    ScreenManager();
    ~ScreenManager();
    virtual void clearScreen() const;      // Função que limpa a tela
};

class Student : public ScreenManager {     // Classe que Faz o gerenciamento dos dados do aluno 
private:
    std::vector<double> grades_;           // Vector que guarda as notas do aluno
    std::string studentName_;              // Nome do aluno
    double grade_;                         // Nota do aluno
    double average_;                       // Media do aluno

public:
    Student();                            // Construtor da classe Student
    ~Student();
    void clearScreen() const override;    // Função que limpa a tela. herdada da classe ScreenManager
    void askStudentName();                // Função que pergunta o nome do aluno
    void calculateGrades();               // Função que calcula as notas do aluno

    std::string getStudentName() const;    // Obtem o nome do aluno 
    std::vector<double> getGrades() const; // Obtem as notas do aluno
};

class Display {                          // Classe que gerencia o que vai ser Mostrado na tela
private:
    std::unique_ptr<Student> obj_;

public:
    Display(std::unique_ptr<Student> obj);
    ~Display();
    void displayStudent();  // Mostra as informações do aluno
};

#endif