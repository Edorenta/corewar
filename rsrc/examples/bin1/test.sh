COR=*.cor
for f in $COR
do
	echo $f
	xxd $f > tmp
	xxd ../bin2/$f > tmp2
	diff tmp tmp2
	rm tmp tmp2
done
