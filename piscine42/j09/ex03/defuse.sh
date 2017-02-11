touch -A -000001 bomb.txt && stat -t %s bomb.txt | awk '{print $9}' | sed 's/\"//g'
