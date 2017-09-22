# 设备列表
adb devices 

# 多台设备连接时，指定设备执行命令
adb -s serialno ${cmd}

adb shell

# 进入真机shell
adb -d shell
# 进入模拟器shell
adb -e shell

adb install *.apk

# 复制手机文件到电脑
adb pull /data/app/com.supercell.clashroyale.wdj-1/base.apk D:\Android\apk