for i in {1..64}
do
  echo $i
  cp $1.dfa $1/$1-$i.dfa
  echo $(echo "obase=2;ibase=10;$i" | bc) >> $1/$1-$i.dfa
done
