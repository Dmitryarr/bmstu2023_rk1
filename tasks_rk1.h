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
char* convertDecToBin(int number);
char* convertBinToHex(const char* binNum);
void writeToFile(const char& fileName, const char* strNum);
void buildTree(int height);
void randFill(float* ar, int N);
void writeToFile5(std::vector<float> avg);
std::vector<float> averStr2DArray(const float* ar, int colCount, int rowCount);
#endif //UNTITLED_TASKS_RK1_H