#! /bin/bash

Date=`date -u -d"+8 hour" +'%Y-%m-%d %H:%M:%S'`

cpu_warn='75'
mem_warn='100'
disk_warn='90'

function cpuW(){

	cpu_idle=`top -b -n 1|grep Cpu|awk '{print $8}'|cut -f 1 -d "."`

	cpuUse=`expr 100 - $cpu_idle`

	if [[ $cpuUse -gt $cpu_warn ]]; then
		echo "CPU使用警告"
		echo -e "CPU>10 詳細資料：\n `top -b -n 1| tail +7 |awk '{if(NR==1)print;else if($9>10) print;}'`"
	else
		echo "CPU使用正常"
		echo -e "詳細資料：\n `top -b -n 1| head -n 17`"
	fi
}

cpuW
