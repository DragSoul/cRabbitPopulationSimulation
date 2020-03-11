CC=gcc
CFLAGS=
LDFLAGS= -lm
EXEC=tp4

all: $(EXEC)

$(EXEC): main.o mt19937ar.o fibo.o rabbit.o rabbit_list.o rabbitTreeStatus.o reverseDistLow.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: mt19937ar.o fibo.o rabbit.o rabbit_list.o

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)