#!/bin/bash

CHAMPS=code/*.s
COR=code/*.cor
cp ../../asm .
for f in $CHAMPS
	do
		valgrind --log-file="tmp" ./asm $f
		echo Compile $f :
		cat tmp | grep "definitely lost"
		cat tmp | grep "indirectly lost"
		rm tmp
		./asm $f
		echo
	done
mv $COR ./bin1/

for f in $CHAMPS
	do
		./zaz_asm $f
	done
mv $COR ./bin2/
cd ./bin1
for f in ./*.cor
	do
		echo $f
		diff <(xxd $f) <(xxd ../bin2/$f)
	done
