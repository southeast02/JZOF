echo -n "Please enter a string of numers: "
read -a arr
len=${#arr[@]}

for ((i=1; i < $len; i++))
do
    for ((j=0; j < $len-i; j++))
    do
        if [ ${arr[$j]} -gt ${arr[$j+1]} ]
        then
            x=${arr[$j]}
            arr[$j]=${arr[$j+1]}
            arr[$j+1]=$x
        fi
    done
done

echo "after sort: ${arr[@]}"
