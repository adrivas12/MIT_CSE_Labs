#sum of the numbers given by the user 

echo "Enter the number of numbers: "
read n
echo "Enter the elements: "
declare -a arr
i=0
while [ $i -lt $((n)) ]
do 
read arr[i]
i=$((i+1))
done 

sum=0
j=0
while [ $j -lt $((n)) ]
do 
sum=$((sum+arr[j]))
j=$((j+1))
done

echo "The sum of all the numbers given is: $sum"
