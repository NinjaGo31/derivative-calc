#include <optional>
#include <string>

enum class TokenType {
    CONSTANT,
    VARIABLE,
    EXPONENT,
    EOT
};

typedef struct Token {
    TokenType token;
    std::optional<std::string> value;
} Token;