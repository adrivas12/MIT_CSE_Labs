#first 'n' odd numbers
echo "Enter n for the number of odd numbers: "
read num
echo " "
echo "first $num odd numbers are: "
i=1
while [ $i -le $((num)) ]
do 
echo -n "$((2*i-1))"
echo " " 
i=$(( i + 1 ))
done 
echo " "
echo " " 
