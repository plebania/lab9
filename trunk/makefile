TARGET   = lab9

IDIR= ./inc
ODIR= ./obj
SDIR= ./src
BDIR= ./bin

SOURCES  := $(wildcard $(SDIR)/*.c)
INCLUDES := $(wildcard $(IDIR)/*.h)

InCFLAGS= -I$(IDIR)



OBJECTS  := $(SOURCES:$(SDIR)/%.c=$(ODIR)/%.o)

$(BDIR)/$(TARGET): $(OBJECTS)
	gcc -o $@ $(LFLAGS) $(OBJECTS)

$(OBJECTS): $(ODIR)/%.o : $(SDIR)/%.c
	$(CC) $(CFLAGS) $(InCFLAGS) -c $< -o $@



