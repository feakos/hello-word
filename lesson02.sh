#1. generálj egy fájlt amiben benne vannak a sorszámok 1-50-ig
#2. ezt a fájlt etesd meg a scripttel
#Arra válaszolj, hogy mi a különbség ezek között
#	- bash lesson01.sh < ez_a_generalt_file.txt
#	- cat ez_a_generalt_file.txt | bash lesson01.sh
#	- seq 50 | bash lesson01.sh
#3. irányítsd át a páratlan sorokat egy fájlba (stdout)
#4. irányítsd át a páratlanokat egy fájlba a párosokat egy másikba
#5. irányítsád át a páros és páratlan számokat megint egy fájlba
# 	(ez trükkös lesz... szerintem)

#!/bin/sh

# ha szeretném csak bash-ből seq 50 >> sorszamok.txt 
# többféleképpen meg lehet ezt is csinálni pl cat, blabla

# cat 

# ha megírom script-ben
i=1
while [ $i -le 50 ]
	do
		echo "$i" > sorszamok.txt
		#i=$((i+1)) #i++
		i=`expr $i + 1` #i++
done

echo 1>kimenet.txt 2>&1
echo "hibaüzenet vagyok!" 1>&2


valami=`expr $i \< 50`
echo 'elso: $valami' #idézőjelek használata 1. Mind string!

valami=`expr $i \> 50` #idézőjelek használata 2. $valami változót is észleli!
echo "masodik: $valami"

cat sorszamok.txt

exit 0

#Első feladat megoldása
#sh lesson01.sh 1>/dev/null
#seq 10 | sh lesson01.sh 1>stdout.txt

#Második feladat megoldása
#sh lesson01.sh 1>stdout.txt 2>stderr.txt
#seq 10 | sh lesson01.sh 2>stderr.txt

#Harmadik feladat megoldása
#sh lesson01.sh 1>stdout.txt 2>&1
#seq 10 | sh lesson01.sh 1>stdout.txt 2>&1

# bit program tesztelése -10 10 között. 

# seq -10 10 | ./bit  2>/dev/null
# seq -10 10 > test01.in
# ./bit < test01.in  2>/dev/null >test01.out
# ./bit < test01.in  2>/dev/null > out
# diff out test01.out