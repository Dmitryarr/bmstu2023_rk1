#include "tasks_rk1.h"
void task_1(void) {
    WorkWithFile go;
}
void task_2(void) {
    const char* n = "result_task2";
    int b1 = -255, b2 = INT_MAX, b3 = 0;
    char* result = convertDecToBin(b1);
    writeToFile(n, result);
    result = convertDecToBin(b2);
    writeToFile(n, result);
    result = convertDecToBin(b3);
    writeToFile(n, result);
}
void task_3(void) {
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
void task4(void) {
    int h = 5;
    buildTree(h);
}

void task_5(void) {
    float ar[10][5];
    for (int i = 0; i < 10; i++) {
        randFill(ar[i], 5);
    }
    std::vector<float> avg = averStr2DArray(*ar, 5, 10);
    writeToFile5(avg);
}
void task_6(void) {
    LinkedList list;
    for (int i = 0; i < 10; i++)
        list.push_back(i);
    list.writeToFileFromHead();
    list.writeToFileFromTail();
}

void task_7(void) {
    LinkedList list;
    for (int i = 0; i < 10; i++)
        list.push_back(i);
    list.insert(4, 2);
    list.insert(100, 9);
    list.insert(-99, 10);
    list.writeToFileFromHead();
    list.writeToFileFromTail();
}
void task_9(void) {
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
    task_1();
    task_2();
    task_3();
    task_4();
    task_5();
    task_6();
    task_7();
    task_9();
    return 0;
}
