#include "tasks_rk1.h"
void task1() {
    WorkWithFile go;
}
void task2() {
    const char* n = "result_task2";
    int b1 = -255, b2 = INT_MAX, b3 = 0;
    char* result = convertDecToBin(b1);
    writeToFile(n, result);
    result = convertDecToBin(b2);
    writeToFile(n, result);
    result = convertDecToBin(b3);
    writeToFile(n, result);
}
void task3() {
    const char* n = "result_task2";
    const char* bin1 = "101010101";
    char* result1 = convertBinToHex(bin1);
    writeToFile(n, result1);
    const char* bin2 = "1111111111111111";
    result1 = convertBinToHex(bin2);
    writeToFile(n, result1);
    const char* bin3 = "00001";
    result1 = convertBinToHex(bin3);
    writeToFile(n, result1);
}
void task4() {
    int h = 5;
    buildTree(h);
}

void task5() {
    float ar[10][5];
    for (int i = 0; i < 10; i++) {
        randFill(ar[i], 5);
    }
    std::vector<float> avg = averStr2DArray(*ar, 5, 10);
    writeToFile5(avg);
}
int task6() {
    LinkedList list;
    for (int i = 0; i < 10; i++)
        list.push_back(i);
    list.writeToFileFromHead();
    list.writeToFileFromTail();
    return 0;
}

int task7() {
    LinkedList list;
    for (int i = 0; i < 10; i++)
        list.push_back(i);
    list.insert(4, 2);
    list.insert(100, 9);
    list.insert(-99, 10);
    list.writeToFileFromHead();
    list.writeToFileFromTail();
    return 0;
}
void task9() {
    std::string s = "((()))[<<>>]{((()))}";
    writeToFile9(s, 1);
    s = "][";
    writeToFile9(s, 0);
    s = "[{]}";
    writeToFile9(s, 0);
    s = "(()";
    writeToFile9(s, 0);
    s = "(<<>{(())}[<<<>{}>()>]>)";
    writeToFile9(s, 0);
}
int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task9();
    return 0;
}
