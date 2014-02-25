TARGET=Sample
CXX=g++
CXXFLAGS=-g -O2 -w
LDFLAGS=-static-libgcc -static-libstdc++
INCDIR=-I"./DxLib/"
LIBDIR=-L"./DxLib/"
LIBS=-lDxLib -lDxUseCLib -lDxDrawFunc -ljpeg -lpng -lzlib -ltheora_static -lvorbis_static -lvorbisfile_static -logg_static -lbulletdynamics -lbulletcollision -lbulletmath

LIBS+=-lgdi32
SRCS = main.cpp Character.cpp Game.cpp Field.cpp Input.cpp InputPad.cpp InputKey.cpp
OBJS:=$(SRCS:.cpp=.o)

.cpp.o:
		$(CXX) $(CXXFLAGS) -c $<

$(TARGET): $(OBJS)
		$(CXX) $(CXXFLAGS) $(LDFLAGS) $(INCDIR) $(LIBDIR) -o $@ $^ $(LIBS)

clean:
	@rm -fr $(TARGET).exe $(OBJS) *~ *.swp
