TARGET = pickomino.out
MAIN = main

DOSSIER_INCLUDE = ./src
DOSSIER_SRC = ./src
DOSSIER_TESTS = ./tests

HEADERS := $(wildcard $(DOSSIER_INCLUDE)/*.h)
SRC := $(wildcard $(DOSSIER_SRC)/*.cpp)
OBJ := $(strip $(patsubst %.cpp, %.o, $(SRC)))

SRC_SANS_MAIN := $(filter-out $(DOSSIER_SRC)/main.cpp, $(SRC))
OBJ_SANS_MAIN := $(patsubst %.cpp, %.o, $(SRC_SANS_MAIN))

CFLAGS=-std=c++11 -Wall -I.
LDFLAGS =
CXX=g++ $(CFLAGS) -c
LD=g++ -o
RM=rm -f

all: $(TARGET)

$(TARGET): $(OBJ)
	$(LD) $@ $(LDFLAGS) $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CFLAGS) -o $@ $<

.PHONY: clean cleanall

clean:
	$(RM) $(DOSSIER_SRC)/*.o $(DOSSIER_SRC)/*.*~
	$(RM) $(DOSSIER_TESTS)/*.o $(DOSSIER_TESTS)/*.out $(DOSSIER_TESTS)/*.*~

cleanall:
	$(RM) $(DOSSIER_SRC)/*.o $(DOSSIER_SRC)/*.*~ $(TARGET)
	$(RM) $(DOSSIER_TESTS)/*.o $(DOSSIER_TESTS)/*.out $(DOSSIER_TESTS)/*.*~ $(TARGET)

format:
	clang-format -i $(SRC) $(HEADERS)

check:
	clang-tidy $(SRC) --quiet -- -std=c++11 -I $(DOSSIER_INCLUDE)

# Tests unitaires
testScoreFinal: $(DOSSIER_TESTS)/testCalculerScoreFinal.out
	./$(DOSSIER_TESTS)/testCalculerScoreFinal.out

testPresenceVers: $(DOSSIER_TESTS)/testsPresenceVers.out
	./$(DOSSIER_TESTS)/testsPresenceVers.out

$(DOSSIER_TESTS)/testCalculerScoreFinal.out: $(DOSSIER_TESTS)/testsUnitaires.o $(DOSSIER_TESTS)/testCalculerScoreFinal.o $(OBJ_SANS_MAIN)
	$(LD) $@ $(LDFLAGS) $^

$(DOSSIER_TESTS)/testCalculerScoreFinal.o: $(DOSSIER_TESTS)/testCalculerScoreFinal.cpp $(HEADERS)
	$(CXX) $(CFLAGS) -o $@ $<

$(DOSSIER_TESTS)/testsPresenceVers.out: $(DOSSIER_TESTS)/testsUnitaires.o $(DOSSIER_TESTS)/testsPresenceVers.o $(OBJ_SANS_MAIN)
	$(LD) $@ $(LDFLAGS) $^

$(DOSSIER_TESTS)/testsPresenceVers.o: $(DOSSIER_TESTS)/testsPresenceVers.cpp $(HEADERS)
	$(CXX) $(CFLAGS) -o $@ $<

$(DOSSIER_TESTS)/testsUnitaires.o: $(DOSSIER_TESTS)/testsUnitaires.cpp $(HEADERS)
	$(CXX) $(CFLAGS) -o $@ $<