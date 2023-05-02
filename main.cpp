#include "tasks_rk1.h"
void task2(void) {
    int b1 = -255, b2 = INT_MAX, b3 = 0;
    char name[] = "result_task2\0";
    char* result = convertDecToBin(b1);
    writeToFile(name[0], result);
    result = convertDecToBin(b2);
    writeToFile(name[0], result);
    result = convertDecToBin(b3);
    writeToFile(name[0], result);
}
void task3(void) {
    char name[] = "result_task2\0";
    const char* bin1 = "101010101";
    char* result1 = convertBinToHex(bin1);
    writeToFile(name[0], result1);
    const char* bin2 = "1111111111111111";
    result1 = convertBinToHex(bin2);
    writeToFile(name[0], result1);
    const char* bin3 = "00001";
    result1 = convertBinToHex(bin3);
    writeToFile(name[0], result1);
}
void task4(void) {
    int h = 5;
    buildTree(h);
}

void task5(void) {
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
int main() {
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    return 0;
}
