link: compile
	gcc writer.o -o writer

compile: main 
	gcc -c -Wall writer.c -o writer.o

main:
	echo "compilation succeeded"

clean:
	rm -f writer.o

clean-all:
	rm -f writer.o
	rm -f writer
