#to find if the input is a palindrome or not

echo "Enter a string: "
read string1
len=`expr $string1 | wc -c`

i=0
flag=0
while [ $i -lt $((len)) ]
do 
if [ string1[i] != string1[len-i-1] ]
then 
flag=1
fi
i=$((i+1))
done

if [ $((flag)) == 1 ]
then
echo "$string1 is not a palindrome"
else
echo "$string1 is a palindrome"
fi

