#even or odd number
echo "Enter the number: "
read num
if [ $((num%2)) -eq 0 ]
then 
echo "number is even."
else
echo "number is odd."
fi
