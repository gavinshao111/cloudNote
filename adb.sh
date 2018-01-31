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

# 卸载app + 包名
adb uninstall com.hase.bclm.client  

# 捕获日志
adb logcat -s ${TAG_NAME}
adb logcat | findstr ${filter}

# 读写系统分区若提示 Read-only file system ，则
adb root 
adb disable-verity 
adb reboot
adb root 
adb remount 

#去掉信号叉号
adb shell settings put global captive_portal_https_url https://www.google.cn/generate_204
