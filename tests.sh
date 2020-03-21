#!/bin/bash
for ((i = 0; i < 100; i++ )) do
	./generator $i 100 > ./tablice/tablice$i.txt 
        ./sortowanie < ./tablice/tablice$i.txt > ./out/out$i.txt
	./sprawdz < ./out/out$i.txt
	if (($? == 1)); 
	then
		echo " ZLE : $i "
		break
	else
		echo " OK : $i "
	fi	
		
done	
