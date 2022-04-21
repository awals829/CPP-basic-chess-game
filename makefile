##############################
###### EXECUTABLE NAMES ######
##############################

MAIN = game
BOARDSOURCE = board
PIECESOURCE = piece
PAWNSOURCE = pawn
KINGSOURCE = king
QUEENSOURCE = queen
BISHOPSOURCE = bishop
ROOKSOURCE = rook
KNIGHTSOURCE = knight
MAINSOURCE = game


###################################
###### TEST EXECUTABLE NAMES ######
###################################

TESTPAWN = testPawn
TESTKING = testKing
TESTQUEEN = testQueen
TESTBISHOP = testBishop
TESTROOK = testRook
TESTKNIGHT = testKnight


#####################
###### MODULES ######
#####################

PROGMODULES = board.o piece.o king.o queen.o rook.o bishop.o knight.o pawn.o game.o ioutil.o
TESTPAWNMODULES = test_pawn.o piece.o pawn.o board.o
TESTKINGMODULES = test_king.o piece.o king.o board.o
TESTQUEENMODULES = test_queen.o piece.o queen.o board.o
TESTBISHOPMODULES = test_bishop.o piece.o bishop.o board.o
TESTROOKMODULES = test_rook.o piece.o rook.o board.o
TESTKNIGHTMODULES = test_knight.o piece.o knight.o board.o


#############################
###### REMOVE COMMANDS ######
#############################

RM = /bin/rm -f *.o $(MAIN) *~  *.*~ *.g*
RMTESTP = $(TESTPAWN)
RMTESTK = $(TESTKING)
RMTESTQ = $(TESTQUEEN)
RMTESTB = $(TESTBISHOP)
RMTESTR = $(TESTROOK)
RMTESTKN = $(TESTKNIGHT)


###################
###### FLAGS ######
###################

CPPFLAGS = -ansi -pedantic-errors -Wall -Wconversion
GCOVFLAGS = -fprofile-arcs -ftest-coverage
GTFLAGS = -lgtest -lpthread -lgtest_main
VALGRIND = valgrind --tool=memcheck --leak-check=full


#######################################
###### EXECUTABLE FILE COMMANDS  ######
#######################################

##########################
###### Main Program ######
$(MAIN): $(PROGMODULES)
	g++ $(CPPFLAGS) $(GCOVFLAGS) $(PROGMODULES) -o $(MAIN)
#	$(VALGRIND) $(MAIN)
	$(MAIN)
	gcov $(MAINSOURCE).cpp 2> /dev/null | grep -A 1 $(MAINSOURCE).cpp

##################################
###### Testing Pawn Program ######
$(TESTPAWN): $(TESTPAWNMODULES)
	g++ $(GCOVFLAGS) $(GTFLAGS) $(TESTPAWNMODULES) -o $(TESTPAWN)
	$(TESTPAWN)
	gcov $(PAWNSOURCE).cpp 2> /dev/null | grep -A 1 $(PAWNSOURCE).cpp

##################################
###### Testing King Program ######
$(TESTKING): $(TESTKINGMODULES)
	g++ $(GCOVFLAGS) $(GTFLAGS) $(TESTKINGMODULES) -o $(TESTKING)
	$(TESTKING)
	gcov $(KINGSOURCE).cpp 2> /dev/null | grep -A 1 $(KINGSOURCE).cpp

###################################
###### Testing Queen Program ######
$(TESTQUEEN): $(TESTQUEENMODULES)
	g++ $(GCOVFLAGS) $(GTFLAGS) $(TESTQUEENMODULES) -o $(TESTQUEEN)
	$(TESTQUEEN)
	gcov $(QUEENSOURCE).cpp 2> /dev/null | grep -A 1 $(QUEENSOURCE).cpp

##################################
###### Testing Rook Program ######
$(TESTROOK): $(TESTROOKMODULES)
	g++ $(GCOVFLAGS) $(GTFLAGS) $(TESTROOKMODULES) -o $(TESTROOK)
	$(TESTROOK)
	gcov $(ROOKSOURCE).cpp 2> /dev/null | grep -A 1 $(ROOKSOURCE).cpp

####################################
###### Testing Bishop Program ######
$(TESTBISHOP): $(TESTBISHOPMODULES)
	g++ $(GCOVFLAGS) $(GTFLAGS) $(TESTBISHOPMODULES) -o $(TESTBISHOP)
	$(TESTBISHOP)
	gcov $(BISHOPSOURCE).cpp 2> /dev/null | grep -A 1 $(BISHOPSOURCE).cpp

####################################
###### Testing Knight Program ######
$(TESTKNIGHT): $(TESTKNIGHTMODULES)
	g++ $(GCOVFLAGS) $(GTFLAGS) $(TESTKNIGHTMODULES) -o $(TESTKNIGHT)
	$(TESTKNIGHT)
	gcov $(KNIGHTSOURCE).cpp 2> /dev/null | grep -A 1 $(KNIGHTSOURCE).cpp


####################################################
###### CLEAN DIRECTORY AND MAKE TESTS COMMAND ######
####################################################

###### Clean Files ######
clean:
	$(RM) $(RMTESTP) $(RMTESTK) $(RMTESTQ) $(RMTESTB) $(RMTESTR) $(RMTESTKN)

###### Run All Functions ######
tests: clean $(TESTKING) $(TESTQUEEN) $(TESTROOK) $(TESTBISHOP) $(TESTKNIGHT) $(TESTPAWN)


##########################################
###### PRIMARY OBJECT FILE CREATION ######
##########################################

###### board.o File Creation ######
board.o: board.cpp Board.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c board.cpp

###### piece.o File Creation ######
piece.o: piece.cpp Piece.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c piece.cpp


######################################
###### CHESS PIECE OBJECT FILES ######
######################################

###### pawn.o File Creation ######
pawn.o: pawn.cpp Pawn.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(PAWNSOURCE).cpp

###### king.o File Creation ######
king.o: king.cpp King.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(KINGSOURCE).cpp

###### queen.o File Creation ######
queen.o: queen.cpp Queen.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(QUEENSOURCE).cpp

###### rook.o File Creation ######
rook.o: rook.cpp Rook.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(ROOKSOURCE).cpp

###### bishop.o File Creation ######
bishop.o: bishop.cpp Bishop.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(BISHOPSOURCE).cpp

###### knight.o File Creation ######
knight.o: knight.cpp Knight.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(KNIGHTSOURCE).cpp


#####################################
###### CHESS TEST OBJECT FILES ######
#####################################

###### test_board.o File Creation ######
test_board.o: test_board.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c test_board.cpp

###### test_piece.o File Creation ######
test_piece.o: test_piece.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c test_piece.cpp

###### test_pawn.o File Creation ######
test_pawn.o: test_pawn.cpp Board.h Piece.h Pawn.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c test_pawn.cpp

###### test_king.o File Creation ######
test_king.o: test_king.cpp Board.h Piece.h King.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c test_king.cpp

###### test_queen.o File Creation ######
test_queen.o: test_queen.cpp Board.h Piece.h Queen.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c test_queen.cpp

###### test_rook.o File Creation ######
test_rook.o: test_rook.cpp Board.h Piece.h Rook.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c test_rook.cpp

###### test_bishop.o File Creation ######
test_bishop.o: test_bishop.cpp Board.h Piece.h Bishop.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c test_bishop.cpp

###### test_knight.o File Creation ######
test_knight.o: test_knight.cpp Board.h Piece.h Knight.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c test_knight.cpp


################################
###### OTHER OBJECT FILES ######
################################

###### game.o File Creation ######
game.o: game.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c game.cpp

###### ioutil.o File Creation ######
ioutil.o: ioutil.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c ioutil.cpp
