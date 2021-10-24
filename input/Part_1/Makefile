CC = g++
CFLAGS = -Wall -g -std=c++11
LDFLAGS = -I../
OBJFILES = code.o ../ft_helper.o dft.o idft.o
TARGET = code
# g++ ${OPENCV_FLAGS} -std=c++11  main.cpp -o simple-demo
# g++ $(pkg-config --cflags --libs /usr/local/Cellar/opencv/4.5.1_3/lib/pkgconfig/opencv4.pc) -std=c++11  main.cpp -o simple-demo

all : ${TARGET}

#${TARGET} :
#	${CC} ${CFLAGS}  code.cpp ../Matrix.h ../Complex.h -o ${TARGET} ${LDFLAGS}
${TARGET} : ${OBJFILES}
	${CC} ${CFLAGS} ${OBJFILES} -o ${TARGET} ${LDFLAGS}

clean :
	rm -f ${TARGET} ${OBJFILES} *~
