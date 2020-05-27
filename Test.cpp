#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"

#include <cassert>

namespace WarGame {
    WarGame::Board board(8, 8);
    TEST_CASE ("legal and illegal moves AND constructors (foot commander)") {
//24
                CHECK(!board.has_soldiers(1));
        board[{0, 0}] = new FootCommander(1);
                CHECK(board[{0, 0}]);
                CHECK(board[{0, 0}]);
        board[{0, 3}] = new FootCommander(1);
                CHECK(board[{0, 3}]);
        board[{0, 7}] = new FootCommander(1);
                CHECK(board[{0, 7}]);
                CHECK(board.has_soldiers(1));
                CHECK(!board.has_soldiers(2));
        board[{7, 0}] = new FootCommander(2);
                CHECK(board[{7, 0}]);
        board[{7, 3}] = new FootCommander(2);
                CHECK(board[{7, 3}]);
        board[{7, 7}] = new FootCommander(2);
                CHECK(board[{7, 7}]);
                CHECK(board.has_soldiers(2));
                CHECK(board.has_soldiers(1));
                CHECK(board.has_soldiers(2));


    }

    TEST_CASE ("FootSoldier VS FootCommander") {//19
        WarGame::Board board(5, 5);
                CHECK(!board.has_soldiers(1));
        board[{0, 0}] = new FootSoldier(1);
                CHECK(board[{0, 0}]);
                CHECK(board[{0, 0}]);
        board[{1, 1}] = new FootCommander(1);
        board[{0, 1}] = new FootSoldier(1);
        board[{0, 2}] = new FootSoldier(1);
                CHECK(board.has_soldiers(1));
                CHECK(!board.has_soldiers(2));
        for (int i = 0; i < 5; i++) {
            board[{4, i}] = new FootSoldier(2);
                    CHECK(board[{4, i}]);
        }

        for (int i = 1; i < 5; i++) {
            board[{4, i}] = new FootSoldier(2);
                    CHECK(board[{4, i}]);
            board.move(2, {4, i}, WarGame::Board::MoveDIR::Down);
                    CHECK(board[{4 - i, i}]);
        }
                CHECK(board.has_soldiers(2));
    }

    TEST_CASE ("FootSoldier VS FootSoldier") {
        WarGame::Board board(8, 8);
                CHECK(!board.has_soldiers(1));
        board[{3, 6}] = new FootSoldier(1);
        CHECK_THROWS((board[{3, 6}] = new FootSoldier(1)));
        CHECK_THROWS((board[{3, 6}] = new FootSoldier(2)));
        board[{5, 3}] = new FootSoldier(1);
        board[{6, 1}] = new FootSoldier(1);
                CHECK(board.has_soldiers(1));
        for (int i = 0; i < 8; i++) {
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
        // CHECK_THROWS(board.move(2, {3, 1}, WarGame::Board::MoveDIR::Up)); //no soldier their
        board[{5, 1}] = new FootSoldier(1);
        board[{7, 1}] = new FootSoldier(1);
        //CHECK_THROWS(board.move(1, {7, 1}, WarGame::Board::MoveDIR::Up)); //outside
        board[{0, 1}] = new FootSoldier(1);
        //CHECK_THROWS(board.move(1, {7, 1}, WarGame::Board::MoveDIR::Down)); //outside
        board[{0, 7}] = new FootSoldier(2);
        //CHECK_THROWS(board.move(2, {0, 7}, WarGame::Board::MoveDIR::Right)); //outside
        board[{0, 0}] = new FootSoldier(2);

        //CHECK_THROWS(board.move(2, {0, 7}, WarGame::Board::MoveDIR::Left)); //outside
    }

    TEST_CASE ("init") {//34
                CHECK(!board.has_soldiers(1));
                CHECK(!board.has_soldiers(1));
                CHECK(!board.has_soldiers(2));
                CHECK(!board.has_soldiers(2));
        for (int i = 0; i < 7; i++) {
            board[{i, 0}] = new FootCommander(1);
            board[{i, 7}] = new FootCommander(2);
            board[{i + 1, 0}] = new FootSoldier(1);
            board[{i + 1, 6}] = new FootSoldier(2);
                    CHECK(board[{i, 0}]);
                    CHECK(board[{i, 0}]);
                    CHECK(board[{i, 7}]);
                    CHECK(board[{i + 1, 6}]);
                    CHECK(board[{i + 1, 0}]);
        }
    }
}



/*#include "doctest.h"
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include <typeinfo>
//#include "Sniper.hpp"
//#include "SniperCommander.hpp"
//#include "Paramedic.hpp"
//#include "ParamedicCommander.hpp"
namespace WarGame {
    WarGame::Board Board1() {

        WarGame::Board board1(10, 10);

        // Add soldiers for player 1:
        board1[{1, 1}] = new FootSoldier(1);
        board1[{3, 3}] = new FootCommander(1);
        //board1[{2, 3}] = new Sniper(1);
        //board1[{4, 5}] = new SniperCommander(1);
        //board1[{3, 4}] = new Paramedic(1);
        //board1[{5, 5}] = new ParamedicCommander(1);

        // Add soldiers for player 2:
        board1[{9, 1}] = new FootSoldier(2);
        board1[{8, 3}] = new FootCommander(2);
        //board1[{7, 3}] = new Sniper(2);
        //board1[{6, 5}] = new SniperCommander(2);
        //board1[{7, 4}] = new Paramedic(2);
        //board1[{6, 6}] = new ParamedicCommander(2);

    }

    WarGame::Board Board2() {
        WarGame::Board board2(12, 12);

        // Add soldiers for player 1:
        board2[{2, 1}] = new FootSoldier(1);
        board2[{2, 3}] = new FootCommander(1);
        //board2[{3, 2}] = new Sniper(1);
        //board2[{1, 5}] = new SniperCommander(1);
        //board2[{9, 9}] = new Paramedic(1);
        //board2[{6, 6}] = new ParamedicCommander(1);

        // Add soldiers for player 2:
        board2[{7, 9}] = new FootSoldier(2);
        board2[{4, 9}] = new FootCommander(2);
        //board2[{10, 11}] = new Sniper(2);
        //board2[{11, 11}] = new SniperCommander(2);
        //board2[{10, 10}] = new Paramedic(2);
        //board2[{9, 0}] = new ParamedicCommander(2);

    }

    WarGame::Board Board3() {

        WarGame::Board board3(4, 4);

        // Add soldiers for player 1:
        board3[{0, 0}] = new FootSoldier(1);
        board3[{1, 1}] = new FootCommander(1);
        //board3[{1, 2}] = new Sniper(1);
        //board3[{2, 1}] = new SniperCommander(1);
        //board3[{3, 1}] = new Paramedic(1);
        //board3[{3.3}] = new ParamedicCommander(1);

        // Add soldiers for player 2:
        board3[{3, 2}] = new FootSoldier(2);
        board3[{2, 2}] = new FootCommander(2);
        //board3[{0, 3}] = new Sniper(2);
        //board3[{0, 2}] = new SniperCommander(2);
        //board3[{2, 3}] = new Paramedic(2);
        //board3[{2, 0}] = new ParamedicCommander(2);

    }

    TEST_CASE ("board 1") {
        WarGame::Board board1 = Board1();
        // CHECK(board1.has_soldiers(1));
        // CHECK(board1.has_soldiers(2));

                CHECK_FALSE(typeid(board1[{1, 1}]) == typeid(FootSoldier));
                CHECK_FALSE(typeid(board1[{3, 3}]) == typeid(FootCommander));
        //CHECK_FALSE(typeid(board1[{2, 3}]) == typeid(Sniper));
        //CHECK_FALSE(typeid(board1[{4, 5}]) == typeid(SniperCommander));
        //CHECK_FALSE(typeid(board1[{{ 3, 4 }])==typeid(Paramedic));
        //CHECK_FALSE(typeid(board1[{5, 5}]) == typeid(ParamedicCommander));

                CHECK_FALSE(typeid(board1[{9, 1}]) == typeid(FootSoldier));
                CHECK_FALSE(typeid(board1[{8, 3}]) == typeid(FootCommander));
        //CHECK_FALSE(typeid(board1[{7, 3}]) == typeid(Sniper));
        //CHECK_FALSE(typeid(board1[{6, 5}]) == typeid(SniperCommander));
        //CHECK_FALSE(typeid(board1[{7, 4}]) == typeid(Paramedic));
        //CHECK_FALSE(typeid(board1[{6, 6}]) == typeid(ParamedicCommander));

                CHECK_FALSE(typeid(board1[{0, 1}]) == typeid(FootSoldier));
                CHECK_FALSE(typeid(board1[{0, 3}]) == typeid(FootCommander));
        //CHECK_FALSE(typeid(board1[{7, 0}]) == typeid(Sniper));
        //CHECK_FALSE(typeid(board1[{6, 4}]) == typeid(SniperCommander));
        //CHECK_FALSE(typeid(board1[{5, 4}]) == typeid(Paramedic));
        //CHECK_FALSE(typeid(board1[{6, 2}]) == typeid(ParamedicCommander));

                CHECK_FALSE(typeid(board1[{5, 1}]) == typeid(FootSoldier));
                CHECK_FALSE(typeid(board1[{0, 6}]) == typeid(FootCommander));
        //CHECK_FALSE(typeid(board1[{4, 8}]) == typeid(Sniper));
        //CHECK_FALSE(typeid(board1[{9, 4}]) == typeid(SniperCommander));
        //CHECK_FALSE(typeid(board1[{3, 4}]) == typeid(Paramedic));
        //CHECK_FALSE(typeid(board1[{2, 2}]) == typeid(ParamedicCommander));

                CHECK_FALSE(typeid(board1[{5, 5}]) == typeid(FootSoldier));
                CHECK_FALSE(typeid(board1[{7, 7}]) == typeid(FootCommander));
        //CHECK_FALSE(typeid(board1[{8, 8}]) == typeid(Sniper));
        //CHECK_FALSE(typeid(board1[{9, 9}]) == typeid(SniperCommander));
        //CHECK_FALSE(typeid(board1[{6, 6}]) == typeid(Paramedic));
        //CHECK_FALSE(typeid(board1[{6, 9}]) == typeid(ParamedicCommander));

        //32
    }
/*
TEST_CASE(Test 2) {
    WarGame::Board board2 = Board2();
            CHECK(board2.has_soldiers(1));
            CHECK(board2.has_soldiers(2));

            CHECK_FALSE(typeid(board2[{1, 1}]) == typeid(FootSoldier));
            CHECK_FALSE(typeid(board2[{3, 3}]) == typeid(FootCommander));
            //CHECK_FALSE(typeid(board2[{4, 5}]) == typeid(SniperCommander));
            //CHECK_FALSE(typeid(board2[{{ 3, 4 }])==typeid(Paramedic))
                                            ;
                                        CHECK_FALSE
                                        (typeid(board2[{5, 5}]) == typeid(ParamedicCommander))
                                                ;

                                        CHECK_FALSE
                                        (typeid(board2[{9, 1}]) == typeid(FootSoldier))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{8, 3}]) == typeid(FootCommander))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{7, 3}]) == typeid(Sniper))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{6, 5}]) == typeid(SniperCommander))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{6, 6}]) == typeid(ParamedicCommander))
                                                ;

                                        CHECK_FALSE
                                        (typeid(board2[{0, 1}]) == typeid(FootSoldier))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{0, 3}]) == typeid(FootCommander))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{7, 0}]) == typeid(Sniper))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{6, 4}]) == typeid(SniperCommander))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{5, 4}]) == typeid(Paramedic))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{6, 2}]) == typeid(ParamedicCommander))
                                                ;

                                        CHECK_FALSE
                                        (typeid(board2[{5, 1}]) == typeid(FootSoldier))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{0, 6}]) == typeid(FootCommander))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{4, 8}]) == typeid(Sniper))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{9, 4}]) == typeid(SniperCommander))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{3, 4}]) == typeid(Paramedic))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{2, 2}]) == typeid(ParamedicCommander))
                                                ;

                                        CHECK_FALSE
                                        (typeid(board1[{5, 5}]) == typeid(FootSoldier))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board1[{7, 7}]) == typeid(FootCommander))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board1[{8, 8}]) == typeid(Sniper))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board1[{9, 9}]) == typeid(SniperCommander))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board1[{6, 6}]) == typeid(Paramedic))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board1[{6, 9}]) == typeid(ParamedicCommander))
                                                ;

                                        CHECK_FALSE
                                        (typeid(board2[{11, 5}]) == typeid(FootSoldier))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{11, 0}]) == typeid(FootCommander))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{9, 8}]) == typeid(Sniper))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{10, 9}]) == typeid(SniperCommander))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{11, 6}]) == typeid(Paramedic))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{0, 9}]) == typeid(ParamedicCommander))
                                                ;

                                        CHECK_FALSE
                                        (typeid(board2[{0, 0}]) == typeid(FootSoldier))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{0, 1}]) == typeid(FootCommander))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{0, 8}]) == typeid(Sniper))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{2, 9}]) == typeid(SniperCommander))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{6, 11}]) == typeid(Paramedic))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{7, 7}]) == typeid(ParamedicCommander))
                                                ;

                                        CHECK_FALSE
                                        (typeid(board2[{6, 1}]) == typeid(FootSoldier))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{1, 4}]) == typeid(FootCommander))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{4, 8}]) == typeid(Sniper))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{11, 2}]) == typeid(SniperCommander))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{4, 11}]) == typeid(Paramedic))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board2[{3, 10}]) == typeid(ParamedicCommander))
                                                ;

                                        //38
                                    }

                                    TEST_CASE(Test 2)
                                    {
                                        WarGame::Board board3 = Board3();
                                        CHECK
                                        (board3.has_soldiers(1))
                                                ;
                                        CHECK
                                        (board3.has_soldiers(2))
                                                ;

                                        CHECK_FALSE
                                        (typeid(board3[{0, 0}]) == typeid(FootSoldier))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board3[{1, 1}]) == typeid(FootCommander))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board3[{1, 2}]) == typeid(SniperCommander))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board3[{
                                            { 2, 1 }])==typeid(Paramedic));
                                                                              CHECK_FALSE
                                                                              (typeid(board3[{3, 1}]) ==
                                                                              typeid(ParamedicCommander))
                                                                                      ;

                                                                              CHECK_FALSE
                                                                              (typeid(board3[{3, 2}]) ==
                                                                              typeid(FootSoldier))
                                                                                      ;
                                                                              CHECK_FALSE
                                                                              (typeid(board3[{2, 2}]) ==
                                                                              typeid(FootCommander))
                                                                                      ;
                                                                              CHECK_FALSE
                                                                              (typeid(board3[{0, 3}]) ==
                                                                              typeid(SniperCommander))
                                                                                      ;
                                                                              CHECK_FALSE
                                                                              (typeid(board3[{0, 2}]) ==
                                                                              typeid(Paramedic))
                                                                                      ;
                                                                              CHECK_FALSE
                                                                              (typeid(board3[2, 3
                                                                          }])==typeid(ParamedicCommander))
                                            ;

                                        CHECK_FALSE
                                        (typeid(board3[{0, 1}]) == typeid(FootSoldier))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board3[{1, 0}]) == typeid(FootCommander))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board3[{1, 3}]) == typeid(SniperCommander))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board3[{2, 0}]) == typeid(Paramedic))
                                                ;
                                        CHECK_FALSE
                                        (typeid(board3[3, 0
                                    }])==typeid(ParamedicCommander));
//20

}
*/
//}
