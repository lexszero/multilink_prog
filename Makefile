TARGET = multilink_prog
SRC = multilink_prog.c unit_cfz.c
CFLAGS += -O0 -ggdb -Wall -Wextra -std=c99 -MD -MP -MF .dep/$(@F).d
LDFLAGS += -ldl

all: $(TARGET)

CC = gcc
COBJ = $(SRC:.c=.o)

$(COBJ): %.o : %.c $(GENSRC)
	$(CC) -c $(CFLAGS) $< -o $@ 

.SECONDARY: $(TARGET)
$(TARGET): $(COBJ)
	$(CC) $(CFLAGS) $(COBJ) -o $@ $(LDFLAGS)

-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)

.PHONY: clean

clean:
	rm -f *.o $(TARGET) $(GENSRC)
	rm -rf .dep
