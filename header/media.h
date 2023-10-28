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
#include <iomanip>

class ScreenManager {                   
public:
    ScreenManager();
    ~ScreenManager();
    virtual void clearScreen() const; 
};

class Student : public ScreenManager {      
private:
    std::vector<float> grades_;           
    std::string studentName_; 
    float grade_;            
    float average_;           

public:
    Student();      
    ~Student();
    void clearScreen() const override;  
    void askStudentName(); 
    void calculateGrades();               

    std::string getStudentName() const;
    float getAverage() const;
};

class Display { 
private:
    std::unique_ptr<Student> obj_;

public:
    Display(std::unique_ptr<Student> obj);
    ~Display();
    void displayStudent();
};

#endif