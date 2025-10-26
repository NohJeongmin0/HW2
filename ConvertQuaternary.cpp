#include "ConvertQuaternary.hpp"
#include <cmath>

long long toDecimal(int inputNum, bool inputType) {
    long long decimalValue = 0;
    long long num = inputNum;
    int digits[8];

    for (int i = 0; i < 8; ++i) {
        digits[i] = num % 10;
        num /= 10;
    }

    long long power = 1;
    if (inputType) {
        for (int i = 0; i < 8; ++i) {
            decimalValue += digits[i] * power;
            powerOf4 *= 4;
        }

        if (digits[7] >= 2) {
            decimalValue -= power;
        }
    }
    else { 
        for (int i = 0; i < 8; ++i) {
            decimalValue += digits[i] * power;
            power *= -4;
        }
    }
    return decimalValue;
}

int fromDecimal(long long decimalValue, bool outputType) {
    long long valueToConvert = decimalValue;
    int outputDigits[NUM_OUTPUT_QUADS] = { 0 };

    if (outputType) { 
        if (valueToConvert < 0) {
            valueToConvert += std::pow(4, 9);
        }

        for (int i = 0; i < 9; ++i) {
            outputDigits[i] = valueToConvert % 4;
            valueToConvert /= 4;
        }
    }
    else { 
        for (int i = 0; i < NUM_OUTPUT_QUADS; ++i) {
            long long remainder = valueToConvert % 4;

            if (remainder < 0) {
                remainder += 4;
            }
            outputDigits[i] = (int)remainder;

            valueToConvert = (valueToConvert - remainder) / (-4);
        }
    }

    long long finalOutput = 0;
    long long multiplier = 1;
    bool leadingZero = true;

    for (int i = 8; i >= 0; --i) {
        if (outputDigits[i] != 0) {
            leadingZero = false;
        }

        if (!leadingZero) {
            finalOutput += outputDigits[i] * multiplier;
            multiplier *= 10;
        }
    }

    if (finalOutput == 0 && outputDigits[0] == 0) {
        return 0;
    }

    return (int)finalOutput;
}
int convertQuaternary(int inputNum, bool inputType) {
    // TODO: Implement this function for converting between negative quaternary notations and 4's complement notations.
    // input: inputNum - an 8-digit integer in either negative quaternary notation or 4's complement notation.
    //        inputType - a boolean value indicating the type of inputNum. If inputType is false, inputNum is in negative quaternary notation. If inputType is true, inputNum is in 4's complement notation.
    // output: The function should return the converted integer
    // You may assume that the inputNum is always a valid 8-digit integer with each digit being 0, 1, 2, or 3.
    // Your code must return a 9-digit integer with each of the digits being 0, 1, 2, or 3.
    // You may ignore any leading zeros in the input and the output.
    // For your reference, the reference solution has somewhere between 50-80 lines of code, including the helper functions.
    long long decimalValue = toDecimal(inputNum, inputType);
    bool outputType = !inputType;
    return fromDecimal(decimalValue, outputType);
}