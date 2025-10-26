#include "AnswerGenerator.hpp"

AnswerSuite::AnswerSuite(const std::string& sid) {
    this->studentID = std::stoll(sid);
    this->cs = this->studentID % ds;
    this->ls = std::stoll(sid.substr(4, 3));
    this->gi = 0;
}

long long AnswerSuite::nextRandom() {
    this->cs = (this->cs + ps[this->gi]) % (ds + this->ls + ps[(this->gi + 1) % std::size(ps)] % ds);
    this->gi = (this->gi + 1) % std::size(ps);
    return cs;
}

void AnswerSuite::shuffle(int* arr, int targetSize) {
    for (int i = targetSize - 1; i > 0; i--) {
        int j = this->nextRandom() % (i + 1);
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

int AnswerSuite::generateRandomQuaternary() {
    int newNum = 0;
    for (int i = 0; i < 8; i++) {
        int digit = this->nextRandom() % 4;
        newNum = newNum * 10 + digit;
    }
    return newNum;
}

int AnswerSuite::solveOnce() {
    int testInput = this->generateRandomQuaternary();
    bool testType = (this->nextRandom() % 2 == 0);
    return convertQuaternary(testInput, testType);
}


void AnswerSuite::test() {
    long long result = 0;
    for (int i = 0; i < 100000; i++) {
        long long testResult = this->solveOnce();
        result = (result + testResult * ((i % 9) + 1)) % 1000000000;
    }

    std::cout << "Final result: " << result << std::endl;
}
