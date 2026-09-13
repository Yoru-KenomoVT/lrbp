CFLAGS = -std=c11 -Wall -Wextra -O2
grade: grade.c checks.h
	$(CC) $(CFLAGS) -o grade grade.c
clean:
	rm -f grade
.PHONY: clean

PREFIX ?= $(HOME)/.local
install: grade
	install -Dm755 grade $(PREFIX)/bin/grade
	@echo "installed to $(PREFIX)/bin/grade"
.PHONY: install
