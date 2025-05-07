all: huffman

huffman: main.o huffmanTree.o huffmanNode.o
	g++ -o huffman main.o huffmanTree.o huffmanNode.o

main.o: main.cpp huffmanTree.h huffmanNode.h
	g++ -c main.cpp

huffmanTree.o: huffmanTree.cpp huffmanTree.h huffmanNode.h
	g++ -c huffmanTree.cpp

huffmanNode.o: huffmanNode.cpp huffmanNode.h
	g++ -c huffmanNode.cpp

clean:
	rm -f *.o huffman