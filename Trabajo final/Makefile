CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		main.o myconnection.o node.o queue.o usuario.o usuariocontroller.o usuariodao.o usuarioviewer.o

LIBS =		-lmysqlcppconn -lmysqlcppconn-static

TARGET =	ejecutable

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
