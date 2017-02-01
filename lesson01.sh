#!/bin/sh
# Írj egy bash scriptet (.sh fájl-t), 
# ami az stdin-en érkező minden páratlan számú sort az stdout-ra ír
# és minden páros számút az stderr-re.
# Irodalom: héjprogramozás könyv (1. fejezet hello world, 6. fejezet: read parancs)

i=1
while read sor
	do
		if [ $((i%2)) -eq 0 ]
		then
			echo $sor
			i=$(($i+1))
		else
			echo $sor 1>&2
			i=$(($i+1))
	fi
done

exit 0
