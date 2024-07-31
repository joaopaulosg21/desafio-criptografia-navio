#include <iostream>
#include <cmath>
#include <array>
#include <vector>

std::string substr(std::string str, int init, int quantity) {
    std::string result;
    for(int i=0; i < quantity;i++) {
        result += str[init];
        init++;
    }
    return result;
}

std::string reverse(char c) {
    std::string str;
    if (c == '0') {
        return str + '1';
    }

    return str + '0';
}

int pow(int num, int exp) {
    int result = 1;
    for(int i=0; i < exp; i++) {
        result *= (num);
    }

    return result;
}

int convertToDecimal(std::string binaryMsg) {
    int count = 0;
    int result = 0;
    for(int i=binaryMsg.size()-1; i >= 0; i--) {
        if(binaryMsg[i] == '1') {
            result += 1 * (pow(2,count));
        }
        count++;
    }

    return result;
}

char decode(std::string msg) {
    std::string result = substr(msg,4, 2) + reverse(msg[6]) + reverse(msg[7]) + substr(msg,0, 4);
    return char(convertToDecimal(result));
}


int main() {
    std::string msg = "10010110 11110111 01010110 00000001 00010111 00100110 01010111 00000001 00010111 01110110 01010111 00110110 11110111 11010111 01010111 00000011";

    int first = 0;
    int last = 8;
    std::string result;
    while (last < msg.size()) {
        result += decode(substr(msg,first, last));
        first = (last + 1);
        last += 9;
    }

    std::cout << result << std::endl;
}
