# makefile.6
# Chapter 26
# Learn C Programming, 2nd Edition
#
# makefile for dealer program
#
# A general makefile
# 1. All source & header files are in the same directory.
# 2. Change ghe macro PROG to the name of the executable.
# 3.


# Compiler & Linker flags

CC      = clang
CCFLAGS = -Wall -Werror -std=c17
LDLIBS  =


# Project files (only need to change PROG to match your program name)

SRCS = $(wildcard *.c)
HDRS = $(wildcard *.h)
OBJS = $(patsubst %.c, %.o , $(SRCS))

PROG = dealer


# Rules

$(PROG): $(OBJS)
	@echo [Sources: $(SRCS)]
	@echo [Headers: $(HDRS)]
	@echo [Objects: $(OBJS)]
	@echo [Program: $(PROG)]
	$(CC) -o $@ $^ $(LDLIBS)
	
%.o: %.c $(HDRS)
	@echo [$< depends on all header files]
	$(CC) $(CCFLAGS) -c $<
	
%.o: %.c %.h
	@echo [$< has a header file of same name]
	$(CC) $(CCFLAGS) -c $<

%.o: %.c
	@echo [$< does not have a header file]
	$(CC) $(CCFLAGS) -c $<


# helper rules

.PHONY: clean
clean:
	@echo [cleaning up]
	rm -f $(OBJS) $(PROG)

.PHONY: run
run:
	@echo [executing $(PROG)]
	$(PROG)

# eof

