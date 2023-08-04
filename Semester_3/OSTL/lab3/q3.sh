#quadratic equation question 

echo "enter a, b and c of the polynomial equation" 
read a 
read b
read c
echo " " 

d=$((b*b-4*a*c))
if [[ $((d)) -gt 0 ]];
then
dis=-1
elif [[ $((d)) -lt 0 ]];
then 
dis=0
fi

case $((dis)) in "0") 
x1=$((-b/2*a)) 
x2=$((x1))
echo "Root 1: $x1" ", Root 2: $x2";; "-1")
echo "No roots found";;

*)
calc=$(echo "sqrt($d)"|bc)
x1=$((-b/2*a+calc/2*a))
x2=$((-b/2*a-calc/2*a))
echo "Root 1: $x1" ", Root 2: $x2";;
esac
echo " "
