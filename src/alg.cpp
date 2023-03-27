// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
int getPriority(char symbol) {
    switch (symbol) {
    case '(':
        return 0;
    case ')':
        return 1;
    case '+':
        return 2;
    case '-':
        return 2;
    case '*':
        return 3;
    case '/':
        return 3;
    }
    return -1;
}
bool Operand(char symbol) {
    if (symbol >= '0' && symbol <= '9')
        return true;
    return false;
}
std::string infx2pstfx(std::string inf) {
    TStack<char, 100> stack;
    std::string out;
    for (char symbol : inf) {
        if (Operand(symbol)) {
            out += symbol;
            out += ' ';
        } else if (getPriority(symbol) == 0) {
            stack.push(symbol);
        } else if (getPriority(symbol) == 1) {
            while (getPriority(stack.get()) != 0) {
                out += stack.get();
                out += ' ';
                stack.pop();
            }
            stack.pop();
        } else {
            while (!stack.isEmpty() && (getPriority(symbol) <= getPriority(stack.get()))) {
                out += stack.get();
                out += ' ';
                stack.pop();
            }
            stack.push(symbol);
        }
    }
    while (!stack.isEmpty()) {
        out += stack.get();
        out += ' ';
        stack.pop();
    }
    out.pop_back();
    return out;
}


int eval(std::string pref) {
    TStack<int, 100> stack;
    for (char symbol : pref) {
        if (symbol >= '0' && symbol <= '9') {
            stack.push(symbol - '0');
        } else if (symbol == '+' || symbol == '-' || symbol == '/' || symbol == '*') {
            int num2 = stack.get();
            stack.pop();
            int num1 = stack.get();
            stack.pop();
            if (symbol == '+') {
                stack.push(num1 + num2);
            } else if (symbol == '-') {
                stack.push(num1 - num2);
            } else if (symbol == '*') {
                stack.push(num1 * num2);
            } else if (symbol == '/') {
                stack.push(num1 / num2);
            }
        }
    }
    return stack.get();
}
