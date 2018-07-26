stat -f "%m" bomb.txt | tr "\t" " " | cut -d " " -f 1 | xargs echo "-1 + " | bc
