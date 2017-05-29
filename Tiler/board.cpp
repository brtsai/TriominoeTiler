//
// Created by Bryan Tsai on 26/05/2017
//

#include "Board.h"

Board::Board (size_t n) {
    dimension = pow(2,n);
    board = std::vector<std::vector<char>>(dimension);

    auto end = board.end();
    for (auto itor = board.begin(); itor != end; ++itor) {
        *itor = std::vector<char> (dimension);
    }
}

void Board::foldBoard (std::function<void(char*)> fn) {
    auto end = board.end();
    for (auto itor = board.begin(); itor != end; ++itor) {
        auto iEnd = itor->end();
        for (auto iItor = itor->begin(); iItor != iEnd; ++iItor) {
            fn(&(*iItor));
        }
    }
}

void Board::fillBoard (char c) {
    auto lambda = [c](char* ch){*ch = c;};
    foldBoard (lambda);
}

void Board::printBoard () {
    auto end = board.end();
    for (auto itor = board.begin(); itor != end; ++itor) {
        auto iEnd = itor->end();
        for (auto iItor = itor->begin(); iItor != iEnd; ++iItor) {
            std::cout << *iItor << ' ';
        }
        std::cout << std::endl;
    }
}


