COMPILE = g++
FLAG = -W -Wall -Werror -pedantic -ansi
OBJS = BBoard

User.o: User.cpp User.h
	g++ -W -Wall -Werror -pedantic -ansi User.cpp

Message.o: Message.cpp Message.h
	g++ -W -Wall -Werror -pedantic -ansi Message.cpp

Topic.o: Topic.cpp Topic.h Message.h
	g++ -W -Wall -Werror -pedantic -ansi Topic.cpp

Reply.o: Reply.cpp Reply.h Message.h
	g++ -W -Wall -Werror -pedantic -ansi Reply.cpp
BBoard.o: BBoard.cpp Topic.h Message.h Reply.h
	g++ -W -Wall -Werror -pedantic -ansi BBoard.cpp

