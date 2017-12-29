# http://blog.csdn.net/andy572633/article/details/7214534
file -Lz * | grep ASCII | cut -d":" -f1 | xargs ls -ltr


# 开放端口: 
sudo iptables -I INPUT -p tcp --dport 8888 -j ACCEPT
# 显示文件夹大小
du -h --max-depth=1 . 
# 查看磁盘空间
df -h
# 抓包
tcpdump -i eth1 host 120.26.86.124 -w 04_12.cap
tcpdump -i eth0 host 192.168.178.174 and port 9112 -w 12_20.cap

# MQ 服务器 公钥 crt 转 pem:
openssl x509 -in mycert.crt -out mycert.pem -outform PEM

# 生成私钥:
openssl genrsa -des3 -out privkey.pem 2048

# zip:
zip -r myfile.zip ./*

# show process started by gavin
ps -aux | grep ^gavin


shell 注意点：通过命令行输入执行与通过.sh脚本执行在转义字符上有所不同，
如命令行输入
./out/ffmTest rtsp://10.34.16.127:8888/realtime/$1234/1/realtime.sdp 在程序中就会变成
./out/ffmTest rtsp://10.34.16.127:8888/realtime/234/1/realtime.sdp 就是因为'$'是特殊符，是变量标识，shell把 $1 当做变量处理。
如需正确输入，则需要输入 /out/ffmTest rtsp://10.34.16.127:8888/realtime/\$1234/1/realtime.sdp
\$ 表示这个 $ 无需转义成标量标识符。
或者将命令保存到 .sh文件，再执行这个脚本文件，也不会把 $ 转义。

# 解压到 ~
tar -zxvf *.gz -C ~

# 读取第一行
sed -n '1,1p' stdout.log

vi打开文件后查看16进制格式
:%!xxd 

# 添加系统服务
cp service.sh /etc/init.d/easydarwin
# 添加开机启动
chkconfig --add easydarwin
# 添加每天2点自动重启任务
crontab -e
# then input: * 2 * * * service easydarwin restart 