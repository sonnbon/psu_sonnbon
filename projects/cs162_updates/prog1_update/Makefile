#
# Connor Baron-Williams
# jcwill@pdx.edu
# Program 1 Updated

CC = gcc
DEBUG = -g
DEFINES = 
OPT = -O3 -g
CFLAGS = $(DEBUG) -Wall -Wshadow -Wunreachable-code -Wredundant-decls \
	-Wmissing-declarations -Wold-style-definition -Wmissing-prototypes \
	-Wdeclaration-after-statement -Wno-return-local-addr -Wuninitialized \
	-Wextra -Werror $(DEFINES) 
PROG1  = prog1_new
PROGS = $(PROG1)

all: $(PROGS)

$(PROG1): $(PROG1).o
	$(CC) $(CFLAGS) -o $@ $^

$(PROG1).o: $(PROG1).cpp
	$(CC) $(CFLAGS) -c $<

opt: clean
	$(MAKE) DEBUG="$(OPT)"

# clean up the compiled files and editor chaff
clean cls:
	rm -f $(PROGS) *.o *~ \#*

# if you like RCS
ci:
	if [ ! -d RCS ] ; then mkdir RCS; fi
	ci -t-none -m"lazy-checkin" -l *.[ch] ?akefile

# if you are in more of a git Boom Boom Pow mood.
# "Gotta git [sic] that"
#   https://www.youtube.com/watch?v=4m48GqaOz90
#git get gat:
#	if [ ! -d .git ] ; then git init; fi
#	git add *.[ch] ?akefile
#	git commit -m"git on with it"

#tar canvas:
	#tar cvfz cs201-${LOGNAME}.tar.gz *.[ch] ?akefile *.txt
