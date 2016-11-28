# http://blog.csdn.net/andy572633/article/details/7214534
file -Lz * | grep ASCII | cut -d":" -f1 | xargs ls -ltr


# 开放端口: 
sudo iptables -I INPUT -p tcp --dport 8888 -j ACCEPT
# 显示文件夹大小
du -h --max-depth=1 . 

tcpdump -i eth0 host 10.34.16.180 -w 15_12.cap


# MQ 服务器 公钥 crt 转 pem:
openssl x509 -in mycert.crt -out mycert.pem -outform PEM

# 生成私钥:
openssl genrsa -des3 -out privkey.pem 2048
