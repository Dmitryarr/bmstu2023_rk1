#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <fstream>
#include <iostream>
#include <locale>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <vector>
#include <tuple>
#include <map>
#include <list>
#include <vector>
#include <stdio.h>
#include <string.h>
#ifndef UNTITLED_TASKS_RK1_H
#define UNTITLED_TASKS_RK1_H
class WorkWithFile {
private:
    char* dataOfFile;
    void readFromFile(const char* fileName);
    void prepareTestFile(const char* fileName);
public:
    WorkWithFile();
    ~WorkWithFile();
    void writeStatInfoToFile(const char* outFile);
};
char* convertDecToBin(int number);
char* convertBinToHex(const char* binNum);
void writeToFile(const char* fileName, int writeAppend, const char* strNum);
void buildTree(int height);
void randFill(float* ar, int N);
void writeToFile5(std::vector<float> avg);
std::vector<float> averStr2DArray(const float* ar, int colCount, int rowCount);
struct Node;
class LinkedList {
private:
    Node* Head;
    Node* Tail;
public:
    LinkedList();
    ~LinkedList();
    void push_back(int);
    void insert(int, int);
    void writeToFileFromHead();
    void writeToFileFromTail();
};
template<class T>
class IData {
protected:
    T* ar;
    int size1;
    int datalen;
public:
    virtual bool addToEnd(T el) {
        return false;
    }
    virtual bool getFromEnd(T& el) {
        return false;
    }
    IData() {
        datalen = 0;
        size1 = 16;
        ar = new T[16];
    }
    ~IData() {
        delete[] ar;
    }
};
template<class T>
class Filo : public IData<T> {
public:
    Filo() : IData<T>() {}
    bool addToEnd(T el) {
        if (IData<T>::datalen == IData<T>::size1) {
            return false;
        }
        IData<T>::ar[IData<T>::datalen++] = el;
        return true;
    }
    bool getFromEnd(T& el) {
        if (IData<T>::datalen == 0) {
            return false;
        }
        el = IData<T>::ar[--IData<T>::datalen];
        return true;
    }
};
void writeToFile9(std::string str, int writeAppend);
bool check(std::string s);
#endif //UNTITLED_TASKS_RK1_H
