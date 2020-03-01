CXX = g++
LD = g++
CXXFLAGS = -std=c++11

OBJS = Character.o Elf.o Warrior.o Wizard.o main.o

EXE = game

#.PHONY: all
all: $(EXE)

$(EXE): $(OBJS)
	$(LD) -o $@ $^

main.o: main.cpp Character.h Elf.h Warrior.h Wizard.h

Character.o: Character.h Character.cpp

Elf.o: Character.h Elf.h Elf.cpp

Warrior.o: Character.h Warrior.h Warrior.cpp

Wizard.o: Character.h Wizard.h Wizard.cpp

clean:
	$(RM) -f $(OBJS)

clobber: clean
	$(RM) -f $(EXE)
