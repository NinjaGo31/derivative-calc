#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

// #include "../include/tokens.hpp"

bool isInvalidPolyFormat(const std::string& poly) {
    if (!poly.empty() && std::isdigit(*(poly.end() - 1))
        && std::isalpha(*(poly.end() - 2))) {
        return true;
    }

    return false;
}

int main(int argc, char* argv[]) {
    std::string expr, buf;
    std::vector<std::string> args;

    std::cout << "Enter an expression: ";
    std::getline(std::cin, expr);

    std::cout << "Expression: " << expr << std::endl;
    
    for (const char& c : expr) {
        std::cout << c << "\n";

        if (std::isalnum(c)) {            
            buf += c;
        } else { /* Whitespace, a special character, or EOT */
            if (isInvalidPolyFormat(buf)) {
                std::cerr << "Invalid expression: " << expr << "\n";
                return -1;
            }
            
            if (!buf.empty()) {
                args.emplace_back(buf);
                buf.clear();
            }
        }
    }

    if (buf.length() > 0) {
        if (std::isdigit(*(buf.end() - 1)) && std::isalpha(*(buf.end() - 2))) {
            std::cerr << "Invalid expression: " << expr << "\n";
            return -1;
        }

        args.emplace_back(buf);
        buf.clear();
    }

    std::cout << "\nPrinting out \"tokens\"...\n";
    std::for_each(args.begin(), args.end(), [](const std::string& str) {
        std::cout << str << "\n";
    });
    return 0;
}