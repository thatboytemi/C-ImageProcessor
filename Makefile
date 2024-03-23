CC = g++
CCFLAGS = -std=c++20

driver : driver.o PGMimageProcessor.o ConnectedComponent.o 
	$(CC) driver.o PGMimageProcessor.o ConnectedComponent.o -o driver $(CCFLAGS)

test: tester.o
	$(CC) tester.o PGMimageProcessor.o ConnectedComponent.o -o tester $(CCFLAGS)

.cpp.o: 
	$(CC) -c $< $(CCFLAGS)


clean:
	rm -f *.o driver.exe