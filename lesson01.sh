#!/bin/sh
# Írj egy bash scriptet (.sh fájl-t), 
# ami az stdin-en érkező minden páratlan számú sort az stdout-ra ír
# és minden páros számút az stderr-re.
# Irodalom: héjprogramozás könyv (1. fejezet hello world, 6. fejezet: read parancs)

darab=0
i=0
while read sor
	do
		if [ $((i%2))==0 ]
		then
		#[ $i -le 10 ]
			(0>&1 echo $sor)
			i=$(($i+1))
		else
			(0>&2 echo $sor)
			i=$(($i+1))
	fi
done
echo $sor
exit 0