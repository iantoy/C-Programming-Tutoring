FILE = file_name_here

build: $(FILE).s
	#gcc -Wall -g $(FILE).s -o $(FILE) -lm -fno-pie -no-pie
	# following line to compile on Vulcan
	gcc -Wall -g $(FILE).s -o $(FILE) -lm

.PHONY: db

db:
	gdb -tui $(FILE)

run:
	./$(FILE)