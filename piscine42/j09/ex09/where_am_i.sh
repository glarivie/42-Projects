adress=$(ifconfig | grep "inet " | awk '{print $2}')
lines=$(ifconfig | grep "inet " | wc -l | sed 's/ //g')

if test -z $lines
then
	echo "Je suis perdu\n" 
else
	for ip in $adress
		do
			echo $ip
		done
fi
