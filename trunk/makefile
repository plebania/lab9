TARGET   = lab9

IDIR= ./inc
ODIR= ./obj
SDIR= ./src
BDIR= ./bin

SOURCES  := $(wildcard $(SDIR)/*.c)
INCLUDES := $(wildcard $(IDIR)/*.h)

CFLAGS= -I$(IDIR) -Wall -Wextra -pedantic


OBJECTS  := $(SOURCES:$(SDIR)/%.c=$(ODIR)/%.o)

$(BDIR)/$(TARGET): $(OBJECTS)
	$(LINKER) $@ $(LFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(ODIR)/%.o : $(SDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"
