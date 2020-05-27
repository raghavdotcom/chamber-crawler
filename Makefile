CXX = g++                                                                       
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla                                                
EXEC = play                                                                
OBJECTS = main.o game/model.o game/game.o game/floor.o view/standard.o view/writtenView.o \
	controller/controller.o controller/keyboard.o	  
DEPENDS = ${OBJECTS:.o=.d}                                                      
                                                                                
${EXEC}: ${OBJECTS}                                                             
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}                                   
                                                                                
-include ${DEPENDS}                                                             
                                                                                
.PHONY: clean                                                                   
                                                                                
clean:                                                                          
	rm ${OBJECTS} ${EXEC} ${DEPENDS}   
	
