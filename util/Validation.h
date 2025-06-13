//
// Created by suaio on 2025-06-13.
//

// #ifndef VALIDATION_H
// #define VALIDATION_H
//
// #endif //VALIDATION_H
#pragma once

namespace Validation {

    // 숫자 문자열인지 확인
    inline bool isNumber(const std::string& input) {
        if (input.empty()) return false;
        for (char ch : input) {
            if (!std::isdigit(ch)) return false;
        }
        return true;
    }

    // 숫자 범위 확인
    inline bool isInRange(const std::string& input, int min, int max) {
        if (!isNumber(input)) return false;
        int num = std::stoi(input);
        return num >= min && num <= max;
    }

    // 빈 문자열 및 공백 방지 체크
    inline bool isNotEmptyOrWhiteSpace(const std::string& input) {
        // 모든 문자 공백 -> false
        for (char ch : input) {
            if (!std::isspace(static_cast<unsigned char>(ch))) return true;
        }
        return false;
    }

    // 저자 이름 유효성 (한글, 영문, 공백)
    inline bool isValidAuthorName(const std::string& name) {
        std::regex pattern("^[a-zA-Z가-힣\\s]+$");
        return isNotEmptyOrWhiteSpace(name) && std::regex_match(name, pattern);
    }

}