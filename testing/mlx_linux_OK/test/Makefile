

INC=%%%%

INCLIB=$(INC)/../lib

CC=gcc

CFLAGS= -I$(INC) -O3 -I..

NAMEX= mlx-testx
NAMEZ= mlx-testz

SRCZ = mainz.c
SRCX = mainx.c

OBJZ = $(SRCZ:.c=.o)
OBJX = $(SRCX:.c=.o)

all	:$(NAMEX) $(NAMEZ)

$(NAMEX)	:$(OBJX)
	$(CC) -o $(NAMEX) $(OBJX) -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm

$(NAMEZ)	:$(OBJZ)
	$(CC) -o $(NAMEZ) $(OBJZ) -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm

clean	:
	rm -f $(NAMEX) $(OBJX) *~ core *.core
	rm -f $(NAMEZ) $(OBJZ) *~ core *.core


re	: clean all
