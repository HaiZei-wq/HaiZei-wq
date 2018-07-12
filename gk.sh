#!/bin/bash


NowTime=`date +"%Y-%m-%d__%H:%M:%S"`

HostName=`hostname`

OS=`cat /etc/issue.net`

NeiHe=`uname -r`

uptime=`uptime -p`

Loadavg=`cut -d " " -f 1-3 /proc/loadavg`


eval $(df -T -m -x tmpfs -x devtmpfs | tail -n +2 | grep "dev" | \
    awk -v Alldisk=0 -v AllAva=0 '{printf("paramount["NR"]=%d;parleft["NR"]=%d;parname["NR"]=%s;\
        usedperc["NR"]=%s;",$3,$5,$7,$6);Alldisk=Alldisk+$3;AllAva=AllAva+$5}\
    END {printf("parnum=%d;Alldisk=%d;AllAva=%d",NR,Alldisk,AllAva)}')

used=$[ (100-$AllAva*100/$Alldisk) ]

mem=(` free -m | head -n 2 | tail -n 1 | awk '{printf $2}'`)
mema=` free -m | head -n 2 | tail -n 1 | awk '{print $3/$2*100}'`
CpuTemp=`cat /sys/class/thermal/thermal_zone0/temp | awk '{print $1/1000}'`

DiskNote=`echo $used | awk '{if ($1>=70) printf"warning";else if ($1>=50) printf"notr" }'`

MemNote=`echo ${mema} | awk '{if($1 >=70) printf"warning";else if($1>=50) printf"note"}'`

CpuNote=`echo $CpuTemp | awk '{if ($1>=70) printf"warning";else if($1>=50) printf"note"}'`

echo "$NowTime $HostName $OS $NeiHe $uptime $Loadavg ${Alldisk} ${used}% $mem ${mema}% $CpuTemp $DiskNote $MemNote $CpuNote"




