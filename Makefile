PREFIX ?= /usr/local

BIN = xkblayout-subscribe
SRC = xkblayout-subscribe.c

.PHONY: all install uninstall clean
.POSIX:

all : $(BIN)

install : $(BIN)
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f $(BIN) $(DESTDIR)$(PREFIX)/bin/$(BIN)
	chmod 755 $(DESTDIR)$(PREFIX)/bin/$(BIN)

uninstall :
	rm -f $(DESTDIR)$(PREFIX)/bin/$(BIN)

clean :
	rm -f $(BIN)

$(BIN) : $(SRC)
	gcc -Wall -O2 $(SRC) -o $(BIN) -lX11
