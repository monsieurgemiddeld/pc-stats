#!/usr/bin/env python
import psutil
import time
import serial

ser=serial.Serial('COM10',9600,timeout=1)
CompTuple=psutil.swap_memory()
MemPercent=CompTuple
print()

def SerialWrite():
    #Raw is the average CPU utilization.
    #psutil does not include that percpu=False yields an average
    #rather than a sum.
    CompTuple=psutil.swap_memory()
    MemPercent=CompTuple[3] #% of memory used.
    CpuUsage=psutil.cpu_percent(interval=1,percpu=False)
    print(CpuUsage)
    print(MemPercent)
    print("____")
    if MemPercent>=95.00:
        ser.write(b'YY')
    elif MemPercent>=90.00 and MemPercent<=95.00:
        ser.write(b'XX')
    elif MemPercent>=88.00 and MemPercent<=90.00:
        ser.write(b'WW')
    elif MemPercent>=84.00 and MemPercent<=88.00:
        ser.write(b'VV')
    elif MemPercent>=80.00 and MemPercent<=84.00:
        ser.write(b'UU')
    elif MemPercent>=76.00 and MemPercent<=80.00:
        ser.write(b'TT')
    elif MemPercent>=72.00 and MemPercent<=76.00:
        ser.write(b'SS')
    elif MemPercent>=68.00 and MemPercent<=72.00:
        ser.write(b'RR')
    elif MemPercent>=64.00 and MemPercent<=68.00:
        ser.write(b'QQ')
    elif MemPercent>=60.00 and MemPercent<=64.00:
        ser.write(b'PP')
    elif MemPercent>=56.00 and MemPercent<=60.00:
        ser.write(b'OO')
    elif MemPercent>=52.00 and MemPercent<=56.00:
        ser.write(b'NN')
    elif MemPercent>=48.00 and MemPercent<=52.00:
        ser.write(b'MM')
    elif MemPercent>=44.00 and MemPercent<=48.00:
        ser.write(b'LL')
    elif MemPercent>=40.00 and MemPercent<=44.00:
        ser.write(b'KK')
    elif MemPercent>=36.00 and MemPercent<=40.00:
        ser.write(b'JJ')
    elif MemPercent>=32.00 and MemPercent<=36.00:
        ser.write(b'II')
    elif MemPercent>=28.00 and MemPercent<=32.00:
        ser.write(b'HH')
    elif MemPercent>=24.00 and MemPercent<=28.00:
        ser.write(b'GG')
    elif MemPercent>=20.00 and MemPercent<=24.00:
        ser.write(b'FF')
    elif MemPercent>=16.00 and MemPercent<=20.00:
        ser.write(b'EE')
    elif MemPercent>=12.00 and MemPercent<=16.00:
        ser.write(b'DD')
    elif MemPercent>=8.00 and MemPercent<=12.00:
        ser.write(b'CC')
    elif MemPercent>=4 and MemPercent<=8:
        ser.write(b'BB')
    elif MemPercent>=0.00 and MemPercent<=4:
        ser.write(b'AA')
    
    if CpuUsage>=90.00:
        ser.write(b'J')
        print('40 to 50, E and repeat sent')
        
    elif CpuUsage>=80.00 and CpuUsage<=90.00:
        ser.write(b'I')
        print('40 to 50, E and repeat sent')
    
    elif CpuUsage>=70.00 and CpuUsage<=80.00:
        ser.write(b'H')
        print('70 to 80, E and repeat sent')
     
    elif CpuUsage>=60.00 and CpuUsage<=70.00:
        ser.write(b'G')
        print('60 to 70, G and repeat sent')

    elif CpuUsage>=50.00 and CpuUsage<=60.00:
        ser.write(b'F')
        print('50 to 60, F and repeat sent')

    elif CpuUsage>=40.00 and CpuUsage<=50.00:
        ser.write(b'E')
        print('40 to 50, E and repeat sent')
        SerialWrite()
    elif CpuUsage>=30.00 and CpuUsage<=40.00:
        ser.write(b'D')
        print('30 to 40, D and repeat sent')

    elif CpuUsage>=20.00 and CpuUsage<=30.00:
        ser.write(b'C')
        print('20 to 30, C sent')

    elif CpuUsage>=10.00 and CpuUsage<=20.00:
        ser.write(b'B')
        print('10 to 20, B sent')
        SerialWrite()
    elif CpuUsage>=0.00 and CpuUsage<=10.00:
        ser.write(b'A')
        
        print('0 to 10 util, A sent')
        
while(1):            
    SerialWrite()

