#factorial of a given number 

echo "Enter a number: "
read num
fact=1
while [ $num -gt 1 ]
do
fact=$((fact*num)) 
num=$((num-1))
done

echo "The factorial of the given number is: $fact"
