##############################
###### EXECUTABLE NAMES ######
##############################

BOARDSOURCE = board.cpp
BOARDHEADER = Board.h

PIECESOURCE = piece.cpp
PIECEHEADER = Piece.h

PAWNSOURCE = pawn.cpp
PAWNHEADER = Pawn.h

KINGSOURCE = king.cpp
KINGHEADER = King.h

QUEENSOURCE = queen.cpp
QUEENHEADER = Queen.h

BISHOPSOURCE = bishop.cpp
BISHOPHEADER = Bishop.h

ROOKSOURCE = rook.cpp
ROOKHEADER = Rook.h

KNIGHTSOURCE = knight.cpp
KNIGHTHEADER = Knight.h

MAINSOURCE = game.cpp
MAINHEADER = Game.h
MAIN = game


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


#############################
###### REMOVE COMMANDS ######
#############################

RM = /bin/rm -f *.o $(MAIN) *~  *.*~ *.g*


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
	gcov $(MAINSOURCE) 2> /dev/null | grep -A 1 $(MAINSOURCE)

##################################
###### Testing Pawn Program ######
$(TESTPAWN): $(TESTPAWNMODULES)
	g++ $(GCOVFLAGS) $(GTFLAGS) $(TESTPAWNMODULES) -o $(TESTPAWN)
	$(TESTPAWN)
	gcov $(PAWNSOURCE) 2> /dev/null | grep -A 1 $(PAWNSOURCE)

##################################
###### Testing King Program ######
$(TESTKING): $(TESTKINGMODULES)
	g++ $(GCOVFLAGS) $(GTFLAGS) $(TESTKINGMODULES) -o $(TESTKING)
	$(TESTKING)
	gcov $(KINGSOURCE) 2> /dev/null | grep -A 1 $(KINGSOURCE)

###################################
###### Testing Queen Program ######
$(TESTQUEEN): $(TESTQUEENMODULES)
	g++ $(GCOVFLAGS) $(GTFLAGS) $(TESTQUEENMODULES) -o $(TESTQUEEN)
	$(TESTQUEEN)
	gcov $(QUEENSOURCE) 2> /dev/null | grep -A 1 $(QUEENSOURCE)

##################################
###### Testing Rook Program ######
$(TESTROOK): $(TESTROOKMODULES)
	g++ $(GCOVFLAGS) $(GTFLAGS) $(TESTROOKMODULES) -o $(TESTROOK)
	$(TESTROOK)
	gcov $(ROOKSOURCE) 2> /dev/null | grep -A 1 $(ROOKSOURCE)

####################################
###### Testing Bishop Program ######
$(TESTBISHOP): $(TESTBISHOPMODULES)
	g++ $(GCOVFLAGS) $(GTFLAGS) $(TESTBISHOPMODULES) -o $(TESTBISHOP)
	$(TESTBISHOP)
	gcov $(BISHOPSOURCE) 2> /dev/null | grep -A 1 $(BISHOPSOURCE)

####################################
###### Testing Knight Program ######
$(TESTKNIGHT): $(TESTKNIGHTMODULES)
	g++ $(GCOVFLAGS) $(GTFLAGS) $(TESTKNIGHTMODULES) -o $(TESTKNIGHT)
	$(TESTKNIGHT)
	gcov $(KNIGHTSOURCE) 2> /dev/null | grep -A 1 $(KNIGHTSOURCE)


#############################
###### CLEAN DIRECTORY ######
#############################

###### Clean Files ######
clean:
	$(RM)


##########################################
###### PRIMARY OBJECT FILE CREATION ######
##########################################

###### board.o File Creation ######
board.o: $(BOARDSOURCE) $(BOARDHEADER)
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(BOARDSOURCE)

###### piece.o File Creation ######
piece.o: $(PIECESOURCE) $(PIECEHEADER)
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(PIECESOURCE)


######################################
###### CHESS PIECE OBJECT FILES ######
######################################

###### pawn.o File Creation ######
pawn.o: $(PAWNSOURCE) $(PAWNHEADER)
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(PAWNSOURCE)

###### king.o File Creation ######
king.o: $(KINGSOURCE) $(KNIGHTHEADER)
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(KINGSOURCE)

###### queen.o File Creation ######
queen.o: $(QUEENSOURCE) $(QUEENHEADER)
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(QUEENSOURCE)

###### rook.o File Creation ######
rook.o: $(ROOKSOURCE) $(ROOKHEADER)
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(ROOKSOURCE)

###### bishop.o File Creation ######
bishop.o: $(BISHOPSOURCE) $(BISHOPHEADER)
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(BISHOPSOURCE)

###### knight.o File Creation ######
knight.o: $(KNIGHTSOURCE) $(KNIGHTHEADER)
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(KNIGHTSOURCE)


################################
###### OTHER OBJECT FILES ######
################################

###### game.o File Creation ######
game.o: $(MAINSOURCE)
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(MAINSOURCE)

###### ioutil.o File Creation ######
ioutil.o: ioutil.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c ioutil.cpp
