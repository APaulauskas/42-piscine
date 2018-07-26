value=$(ifconfig | grep inet | grep broadcast | cut -d ' ' -f 2)
if [ -z "$value" ]
then
	echo "I am lost!"
else
	echo "$value"
fi
