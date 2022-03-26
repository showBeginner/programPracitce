#! /bin/bash



psAnswer=`ps -au > ps.log`
search=`find . -name ps.log`
searchcpu=`find . -name sortCUP.log`

#對ps -au 取出第一行&&取出除了第一行以外去做CPU與memory排序,把結果輸出到sortCPU.log
sortlog=`(ps -au |head -1 && (ps -au|tail +2)|sort -rk3 -rk4) > sortCPU.log` 

if [[ !$search && ! `find . -name sortCPU.log` ]]; then

	echo -e  " `touch ps.log && touch sortCPU.log`  "
	echo -e  " $psAnswer "
	echo -e " $sortlog "
else
	echo -e  " $psAnswer"
	echo -e " $sortlog "
fi
echo " `(awk 'FNR==1 {print} $4>3 {print}' sortCPU.log |sed -e '5d') >warning.txt` "
echo -e " `ls -l` "

