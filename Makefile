binName = shirazisalad

compile:
	g++ -o $(binName) $(binName).cpp;

install: compile
	mv $(binName) ~/.local/bin/

uninstall:
	rm ~/.local/bin/$(binName)

clean:
	rm $(binName).c $(binName)
