cat "$1" | tr "\t" " " | grep -i "^nicolas bauer" | grep "[0-9]\{3\}-[0-9]\{4\}" | rev | cut -d ' ' -f 2 | rev
