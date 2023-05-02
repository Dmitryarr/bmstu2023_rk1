#include "tasks_rk1.h"
char* convertDecToBin(int number) {
    int arr[64], i = 0, count = 0, ok = 0;
    char result[65] = "";
    for (int i = 63; i >= 0; i--) {
        arr[i] = (number & 1);
        number = number >> 1;
    }
    for (int j = 0; j < 64; j++) {
        if (arr[j] == 1) {
            strcat(result, "1");
        }
        if (arr[j] == 0 && strcmp(result, "") > 0) {
            strcat(result, "0");
        }
    }
    if (strcmp(result, "") == 0)
        strcat(result, "0");
    strcat(result, "\0");
    char* result1 = result;
    return result1;
}
char* convertBinToHex(const char* binNum) {
    int len = strlen(binNum), add = 0, count = 0;
    while (count < len)
        count += 4;
    add = count - len;
    char result[255] = "";
    char ad[255] = "";
    const char a[4] = {};
    for (int i = 0; i < add; i++) {
        strcat(ad, "0");
    }
    strcat(ad, binNum);
    strcat(ad, "\0");
    for (int j = 4; ad[j - 1] != NULL; j += 4) {
        char arr[5] = "";
        for (int i = 0; i < 4; i++) {
            arr[i] = ad[j - 4 + i];
        }
        if (strcmp(arr, "0001") == 0)  strcat(result, "1");
        if (strcmp(arr, "0010") == 0)  strcat(result, "2");
        if (strcmp(arr, "0011") == 0)  strcat(result, "3");
        if (strcmp(arr, "0100") == 0)  strcat(result, "4");
        if (strcmp(arr, "0101") == 0)  strcat(result, "5");
        if (strcmp(arr, "0110") == 0)  strcat(result, "6");
        if (strcmp(arr, "0111") == 0)  strcat(result, "7");
        if (strcmp(arr, "1000") == 0)  strcat(result, "8");
        if (strcmp(arr, "1001") == 0)  strcat(result, "9");
        if (strcmp(arr, "1010") == 0)  strcat(result, "A");
        if (strcmp(arr, "1011") == 0)  strcat(result, "B");
        if (strcmp(arr, "1100") == 0)  strcat(result, "C");
        if (strcmp(arr, "1101") == 0)  strcat(result, "D");
        if (strcmp(arr, "1110") == 0)  strcat(result, "E");
        if (strcmp(arr, "1111") == 0)  strcat(result, "F");
        if (strcmp(arr, "0000") == 0 && strcmp(result, "") > 0) {
            strcat(result, "0");
        }
    }
    if (strcmp(result, "") == 0)
        strcat(result, "0");
    char* result1 = result;
    return result1;
}
void writeToFile(const char* fileName, int writeAppend, const char* strNum) {
    FILE* fLog;
    char str[65] = "";
    strcpy(str, strNum);
    if (writeAppend == 0) {
        fLog = fopen(fileName, "a");
        for (int i = 0; i < 64; i++)
            fprintf(fLog, "%c", str[i]);
        fprintf(fLog, "\n");
        fclose(fLog);
    }
    if (writeAppend == 1) {
        fLog = fopen(fileName, "w");
        for (int i = 0; i < 64; i++)
            fprintf(fLog, "%c", str[i]);
        fprintf(fLog, "\n");
        fclose(fLog);
    }
}
void buildTree(int height) {
    int h = height, k = 0, j = 0;
    for (int i = 0; i < height; i++) {
        for (; k < h-1; k++) {
            std::cout << " ";
        }
        for (; j < 2 * i + 1; j++) {
            std::cout << "*";
        }
        k = 0;
        j = 0;
        h--;
        std::cout << std::endl;
    }
}
void randFill(float* ar, int N) {
    for (int i = 0; i < N; i++) {
        ar[i] = static_cast<float>(rand()) / RAND_MAX;
    }
}

void writeToFile5(std::vector<float> avg) {
    FILE* fLog;
    fLog = fopen("result_task5", "a");
    for (int i = 0; i < avg.size(); i++) {
        fprintf(fLog, "[%d]  :\t[%f]\n", i, avg[i]);
    }
    fclose(fLog);
}
std::vector<float> averStr2DArray(const float* ar, int colCount, int rowCount) {
    std::vector<float> average;
    for (int i = 0; i < rowCount; i++) {
        float sum = 0;
        for (int j = 0; j < colCount; j++) {
            sum += *(ar + i * colCount + j);
        }
        float avg = sum / colCount;
        average.push_back(avg);
    }
    return average;
}
struct Node {
    Node* next;
    Node* prev;
    int nameNode;
    static int countNodes;
    Node() {
        next = nullptr;
        prev = nullptr;
        this->nameNode = 0;
    }
    Node(int _nameNode) {
        next = nullptr;
        prev = nullptr;
        countNodes++;
        this->nameNode = _nameNode + 1;
    }
    ~Node() {
        countNodes--;
    }
};
int Node::countNodes = 0;
LinkedList::LinkedList() {
    Head = nullptr;
    Tail = nullptr;
}
LinkedList::~LinkedList() {
    Node::countNodes = 0;
}
void LinkedList::push_back(int nameNode) {
    Node* temp = new Node(nameNode);
    if (Head == nullptr) {
        Head = temp;
        Tail = temp;
        return;
    }
    Tail->next = temp;
    temp->prev = Tail;
    Tail = temp;
}
void LinkedList::insert(int nameNode, int position) {
    Node* temp = new Node(nameNode);
    if (Head == nullptr) {
        Head = temp;
        Tail = temp;
        return;
    }
    if (position < 0 || position > Node::countNodes)
        return;
    if (position == 1) {
        temp->next = Head;
        Head->prev = temp;
        Head = temp;
        return;
    }
    Node* curr = Head;
    for (int i = 1; i < position - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }
    if (curr == nullptr) {
        Tail->next = temp;
        temp->prev = Tail;
        Tail = temp;
        return;
    }
    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = temp;
    temp->prev = curr;
}
void LinkedList::writeToFileFromHead() {
    FILE* fLog;
    fLog = fopen("result_task6", "a");
    Node* temp = Head;
    for (int i = 0; i < Node::countNodes; i++) {
        fprintf(fLog, "%d\t", temp->nameNode);
        temp = temp->next;
    }
    fprintf(fLog, "\n");
    fclose(fLog);
}
void  LinkedList::writeToFileFromTail() {
    FILE* fLog;
    fLog = fopen("result_task6", "a");
    Node* temp = Tail;
    for (int i = 0; i < Node::countNodes; i++) {
        fprintf(fLog, "%d\t", temp->nameNode);
        temp = temp->prev;
    }
    fprintf(fLog, "\n");
    fclose(fLog);
}
bool check(std::string s) {
    std::map<char, char> bracket = { {'[', ']'}, {'(', ')'}, {'{', '}'}, {'<', '>'} };
    std::map<char, int> bracket_open_or_close = { {'[', 1}, {'(', 1}, {'{', 1}, {'<', 1}, {']', 0}, {')', 0}, {'}', 0}, {'>', 0} };
    Filo<char> work;
    char arr;
    for (int i = 0; i < s.size(); i++) {
        if (bracket_open_or_close[s[i]] == 1) {
            work.addToEnd(s[i]);
        }
        if (bracket_open_or_close[s[i]] == 0) {
            work.getFromEnd(arr);
            if (bracket[arr] != s[i])
                return false;
        }
    }
    if (work.getFromEnd(arr))
        return false;
    return true;
}
void writeToFile9(std::string s, int writeAppend) {
    FILE* fLog;
    if (writeAppend == 0) {
        fLog = fopen("result_task9", "a");
        for (int i = 0; i < s.size(); i++) {
            fprintf(fLog, "%c", s[i]);
        }
        if (check(s) == 1) {
            fprintf(fLog, " - %s\n", "true");
            fclose(fLog);
        }
        fprintf(fLog, " - %s\n", "false");
        fclose(fLog);
    }
    if (writeAppend == 1) {
        fLog = fopen("result_task9", "w");
        for (int i = 0; i < s.size(); i++) {
            fprintf(fLog, "%c", s[i]);
        }
        if (check(s) == 1) {
            fprintf(fLog, " - %s\n", "true");
            fclose(fLog);
        }
        fprintf(fLog, " - %s\n", "false");
        fclose(fLog);
    }
}
