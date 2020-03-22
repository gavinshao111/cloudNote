# cp /data/*/base.apk to /sdcard/backup/apps/ and# rename to *.apk
# com.sina.weibo-1/base.apk -> com.sina.weibo-1 -> weibo-1.apk

mkdir /sdcard/backup/apps
filelist=`ls /data/app/*/base.apk`
for file in $filelist
do
	echo ${file}
	tmp=${file%/*}
	tmp=${tmp##*.}
	#echo ${tmp}
	cp -a ${file} /sdcard/backup/apps/${tmp}.apk
done

# 然后通过adb pull 复制到pc
adb pull sdcard/backup/apps E:\brush\sagit\backup\

# #：表示从左边算起第一个
# %：表示去掉从右边算起到第一个
# ##：表示从左边算起最后一个
# %%：表示从右边算起最后一个
#${file%*/} or ${file#/*} 无效

# install apk
pm install /sdcard/backup/apps/myrtspclient-1.apk

#  How Android Studio install and launch a app:
12/12 09:36:41: Launching app
$ adb push /home/gavin/project/MyRTSPClient/app/build/outputs/apk/app-debug.apk /data/local/tmp/com.leapmotor.gavin.myrtspclient
$ adb shell pm install -r "/data/local/tmp/com.leapmotor.gavin.myrtspclient"
	pkg: /data/local/tmp/com.leapmotor.gavin.myrtspclient
Success


$ adb shell am start -n "com.leapmotor.gavin.myrtspclient/com.leapmotor.gavin.myrtspclient.MainActivity" -a android.intent.action.MAIN -c android.intent.category.LAUNCHER
