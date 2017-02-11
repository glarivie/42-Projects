cat contacts_easy.txt | grep -i "Nicolas\tBomber" | sed q | awk '{print $3}'
