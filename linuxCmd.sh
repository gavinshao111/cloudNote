# http://blog.csdn.net/andy572633/article/details/7214534
file -Lz * | grep ASCII | cut -d":" -f1 | xargs ls -ltr


# ���Ŷ˿�: 
sudo iptables -I INPUT -p tcp --dport 8888 -j ACCEPT
# ��ʾ�ļ��д�С
du -h --max-depth=1 . 

tcpdump -i eth1 host 10.34.16.127 -w 12_19.cap


# MQ ������ ��Կ crt ת pem:
openssl x509 -in mycert.crt -out mycert.pem -outform PEM

# ����˽Կ:
openssl genrsa -des3 -out privkey.pem 2048

# zip:
zip -r myfile.zip ./*

# show process started by gavin
ps -aux | grep ^gavin


shell ע��㣺ͨ������������ִ����ͨ��.sh�ű�ִ����ת���ַ���������ͬ��
������������
./out/ffmTest rtsp://10.34.16.127:8888/realtime/$1234/1/realtime.sdp �ڳ����оͻ���
./out/ffmTest rtsp://10.34.16.127:8888/realtime/234/1/realtime.sdp ������Ϊ'$'����������Ǳ�����ʶ��shell�� $1 ������������
������ȷ���룬����Ҫ���� /out/ffmTest rtsp://10.34.16.127:8888/realtime/\$1234/1/realtime.sdp
\$ ��ʾ��� $ ����ת��ɱ�����ʶ����
���߽�����浽 .sh�ļ�����ִ������ű��ļ���Ҳ����� $ ת�塣