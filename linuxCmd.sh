# http://blog.csdn.net/andy572633/article/details/7214534
file -Lz * | grep ASCII | cut -d":" -f1 | xargs ls -ltr


# ���Ŷ˿�: 
sudo iptables -I INPUT -p tcp --dport 8888 -j ACCEPT
# ��ʾ�ļ��д�С
du -h --max-depth=1 . 

tcpdump -i eth0 host 10.34.16.180 -w 15_12.cap


# MQ ������ ��Կ crt ת pem:
openssl x509 -in mycert.crt -out mycert.pem -outform PEM

# ����˽Կ:
openssl genrsa -des3 -out privkey.pem 2048
