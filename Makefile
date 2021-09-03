#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres
DEBUGGER = gdb

INC = 
CFLAGS = -Wall -Wextra -O0
RESINC = 
LIBDIR =
LIB = 
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS)
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS) -s -lSDL2 -lSDL2_image -lSDL2_ttf -pedantic -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes -Wmissing-prototypes -Wformat=2 -Wno-unused-parameter -fasynchronous-unwind-tables -fstack-clash-protection -g 
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = bin/Debug/ball_shooter

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS)
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS)
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = bin/Release/ball_shooter

OBJ_DEBUG = $(OBJDIR_DEBUG)/CApp.o $(OBJDIR_DEBUG)/CApp_OnCleanup.o $(OBJDIR_DEBUG)/CApp_OnEvent.o $(OBJDIR_DEBUG)/CApp_OnInit.o $(OBJDIR_DEBUG)/CApp_OnLoop.o $(OBJDIR_DEBUG)/CApp_OnRender.o $(OBJDIR_DEBUG)/LBullet.o $(OBJDIR_DEBUG)/LEntity.o $(OBJDIR_DEBUG)/LShoorter.o $(OBJDIR_DEBUG)/LTexture.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/CApp.o $(OBJDIR_RELEASE)/CApp_OnCleanup.o $(OBJDIR_RELEASE)/CApp_OnEvent.o $(OBJDIR_RELEASE)/CApp_OnInit.o $(OBJDIR_RELEASE)/CApp_OnLoop.o $(OBJDIR_RELEASE)/CApp_OnRender.o $(OBJDIR_RELEASE)/LBullet.o $(OBJDIR_RELEASE)/LEntity.o $(OBJDIR_RELEASE)/LShoorter.o $(OBJDIR_RELEASE)/LTexture.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)

after_debug: 
	

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)/CApp.o: CApp.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c CApp.cpp -o $(OBJDIR_DEBUG)/CApp.o

$(OBJDIR_DEBUG)/CApp_OnCleanup.o: CApp_OnCleanup.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c CApp_OnCleanup.cpp -o $(OBJDIR_DEBUG)/CApp_OnCleanup.o

$(OBJDIR_DEBUG)/CApp_OnEvent.o: CApp_OnEvent.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c CApp_OnEvent.cpp -o $(OBJDIR_DEBUG)/CApp_OnEvent.o

$(OBJDIR_DEBUG)/CApp_OnInit.o: CApp_OnInit.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c CApp_OnInit.cpp -o $(OBJDIR_DEBUG)/CApp_OnInit.o

$(OBJDIR_DEBUG)/CApp_OnLoop.o: CApp_OnLoop.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c CApp_OnLoop.cpp -o $(OBJDIR_DEBUG)/CApp_OnLoop.o

$(OBJDIR_DEBUG)/CApp_OnRender.o: CApp_OnRender.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c CApp_OnRender.cpp -o $(OBJDIR_DEBUG)/CApp_OnRender.o

$(OBJDIR_DEBUG)/LBullet.o: LBullet.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c LBullet.cpp -o $(OBJDIR_DEBUG)/LBullet.o

$(OBJDIR_DEBUG)/LEntity.o: LEntity.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c LEntity.cpp -o $(OBJDIR_DEBUG)/LEntity.o

$(OBJDIR_DEBUG)/LShoorter.o: LShoorter.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c LShoorter.cpp -o $(OBJDIR_DEBUG)/LShoorter.o

$(OBJDIR_DEBUG)/LTexture.o: LTexture.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c LTexture.cpp -o $(OBJDIR_DEBUG)/LTexture.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)/CApp.o: CApp.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c CApp.cpp -o $(OBJDIR_RELEASE)/CApp.o

$(OBJDIR_RELEASE)/CApp_OnCleanup.o: CApp_OnCleanup.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c CApp_OnCleanup.cpp -o $(OBJDIR_RELEASE)/CApp_OnCleanup.o

$(OBJDIR_RELEASE)/CApp_OnEvent.o: CApp_OnEvent.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c CApp_OnEvent.cpp -o $(OBJDIR_RELEASE)/CApp_OnEvent.o

$(OBJDIR_RELEASE)/CApp_OnInit.o: CApp_OnInit.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c CApp_OnInit.cpp -o $(OBJDIR_RELEASE)/CApp_OnInit.o

$(OBJDIR_RELEASE)/CApp_OnLoop.o: CApp_OnLoop.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c CApp_OnLoop.cpp -o $(OBJDIR_RELEASE)/CApp_OnLoop.o

$(OBJDIR_RELEASE)/CApp_OnRender.o: CApp_OnRender.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c CApp_OnRender.cpp -o $(OBJDIR_RELEASE)/CApp_OnRender.o

$(OBJDIR_RELEASE)/LBullet.o: LBullet.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c LBullet.cpp -o $(OBJDIR_RELEASE)/LBullet.o

$(OBJDIR_RELEASE)/LEntity.o: LEntity.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c LEntity.cpp -o $(OBJDIR_RELEASE)/LEntity.o

$(OBJDIR_RELEASE)/LShoorter.o: LShoorter.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c LShoorter.cpp -o $(OBJDIR_RELEASE)/LShoorter.o

$(OBJDIR_RELEASE)/LTexture.o: LTexture.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c LTexture.cpp -o $(OBJDIR_RELEASE)/LTexture.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

