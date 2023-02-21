export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/cdf/lib/

PROGRAM = bnd
OBJS = mca_ave.o create_cdf.o gattr.o vattr.o
SRCS = mca_ave.c create_cdf.c gattr.c vattr.c
HEADER = average.h
#LIBDIR = /home/local/centos.local/lib
#INCDIR = /home/local/centos.local/include

$(PROGRAM):	$(OBJS)
	gcc -o $(PROGRAM) $(OBJS) -lcdf -lm -lc -L /usr/local/cdf/lib/
$(OBJS):        $(HEADER)
.c.o:
	gcc -c $<
clean:
	rm $(OBJS) $(PROGRAM)
