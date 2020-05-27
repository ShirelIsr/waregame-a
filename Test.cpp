#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"

#include <cassert>

namespace WarGame {
    WarGame::Board board(10, 10);
    TEST_CASE ("moves && constructors of FootCommender") {

         board[{1, 1}] = new FootCommander(1);
         board[{0, 3}] = new FootCommander(1);
         board[{0, 7}] = new FootCommander(1);

                CHECK(board.has_soldiers(1));
                CHECK(board[{1, 1}]);
                CHECK(board[{1, 1}]);
                CHECK(board[{0, 3}]); 
                CHECK(board[{0, 7}]);
                CHECK(board.has_soldiers(1));
                CHECK(!board.has_soldiers(2));

        board[{7, 0}] = new FootCommander(2);
        board[{7, 3}] = new FootCommander(2);
        board[{7, 7}] = new FootCommander(2);

                CHECK(board[{7, 0}]);
                CHECK(board[{7, 3}]);
                CHECK(board[{7, 7}]);
                CHECK(board.has_soldiers(2));
                CHECK(board.has_soldiers(1));
                CHECK(board.has_soldiers(2));


    }

    TEST_CASE ("FootSoldier VS FootCommander") {//19
        WarGame::Board board(6, 6);

                CHECK(!board.has_soldiers(1));

        board[{0, 0}] = new FootSoldier(1);
        board[{1, 1}] = new FootCommander(1);
        board[{0, 1}] = new FootSoldier(1);
        board[{0, 2}] = new FootSoldier(1);

                CHECK(board[{0, 0}]);
                CHECK(board[{0, 0}]);
                CHECK(board.has_soldiers(1));
                CHECK(!board.has_soldiers(2));

        for (int i = 0; i <= 5; i++)
         {
            board[{5, i}] = new FootSoldier(2);
                    CHECK(board[{5, i}]);
        }

        for (int i = 1; i<= 5; i++)
         {
            board[{5, i}] = new FootSoldier(2);
                    CHECK(board[{4, i}]);
            board.move(2, {5, i}, WarGame::Board::MoveDIR::Down);
                    CHECK(board[{5 - i, i}]);
        }
                CHECK(board.has_soldiers(2));
    }

    TEST_CASE ("FootSoldier VS FootSoldier") 
    {
        WarGame::Board board(10, 10);
                CHECK(!board.has_soldiers(1));
        board[{3, 6}] = new FootSoldier(1);
        board[{5, 3}] = new FootSoldier(1);
        board[{6, 1}] = new FootSoldier(1);

        CHECK_THROWS((board[{3, 6}] = new FootSoldier(1)));
        CHECK_THROWS((board[{3, 6}] = new FootSoldier(2)));
   
         CHECK(board.has_soldiers(1));

        for (int i = 0; i <= 9; i++)
         {
            board[{i, i}] = new FootSoldier(1);
                    CHECK(board.has_soldiers(1));
                    CHECK(!board.has_soldiers(2));
        }
                CHECK(!board.has_soldiers(2));
    }

    TEST_CASE ("moves outside AND illegal moves") {
                CHECK(!board.has_soldiers(1));
        board[{5, 1}] = new FootSoldier(1);
        // CHECK_THROWS(board[{5,2}] = new FootSoldier(3));
        CHECK_THROWS(board.move(1, {6, 1}, WarGame::Board::MoveDIR::Up)); //no soldier their
        CHECK_THROWS(board.move(1, {6, 1}, WarGame::Board::MoveDIR::Up)); //no soldier their
        CHECK_THROWS(board.move(2, {5, 1}, WarGame::Board::MoveDIR::Up)); //no soldier their
        CHECK_THROWS(board.move(2, {5, 1}, WarGame::Board::MoveDIR::Down)); //no soldier their
        CHECK_THROWS(board.move(2, {5, 1}, WarGame::Board::MoveDIR::Down)); //no soldier their
        CHECK_THROWS(board.move(2, {5, 1}, WarGame::Board::MoveDIR::Right)); //no soldier their
        CHECK_THROWS(board.move(2, {5, 1}, WarGame::Board::MoveDIR::Right)); //no soldier their
        CHECK_THROWS(board.move(2, {5, 1}, WarGame::Board::MoveDIR::Left)); //no soldier their
        CHECK_THROWS(board.move(2, {5, 1}, WarGame::Board::MoveDIR::Left)); //no soldier their
                CHECK(!board.has_soldiers(2));
                CHECK(!board.has_soldiers(2));
        board[{5, 4}] = new FootSoldier(2);
        board[{5, 1}] = new FootSoldier(1);
        board[{7, 1}] = new FootSoldier(1);
        board[{0, 1}] = new FootSoldier(1);
        board[{0, 7}] = new FootSoldier(2);
        board[{0, 0}] = new FootSoldier(2);

    }

    TEST_CASE ("Placing players") 
    {
                CHECK(!board.has_soldiers(1));
                CHECK(!board.has_soldiers(1));
                CHECK(!board.has_soldiers(2));
                CHECK(!board.has_soldiers(2));
        for (int i = 0; i < 9; i++) {
            board[{i, 0}] = new FootCommander(1);
            board[{i, 9}] = new FootCommander(2);
            board[{i + 1, 0}] = new FootSoldier(1);
            board[{i + 1, 8}] = new FootSoldier(2);
                    CHECK(board[{i, 0}]);
                    CHECK(board[{i, 0}]);
                    CHECK(board[{i, 9}]);
                    CHECK(board[{i + 1, 8}]);
                    CHECK(board[{i + 1, 0}]);
        }
    }
}


