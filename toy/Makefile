# makfile configuration
COMMON_OBJECTS  = main.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include -L../lib

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR		= msp430-elf-ar

all: piano.elf libLcd.a

#additional rules for files
libLcd.a: font-11x16.o font-5x7.o font-8x12.o lcdutils.o lcddraw.o piano_images.o

	$(AR) crs $@ $^

lcddraw.o: lcddraw.c lcddraw.h lcdutils.h
lcdutils.o: lcdutils.c lcdutils.h
piano_images.o:

install: libLcd.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

piano.elf: ${COMMON_OBJECTS} interrupt_handler.o buzzer.o switches.o led.o main.o libLcd.a ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: piano.elf
	msp430loader.sh piano.elf

clean:
	rm -f *.o *.elf *~
	rm -f libLcd.a *.o\
