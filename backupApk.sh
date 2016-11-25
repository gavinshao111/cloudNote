# cp /data/*/base.apk to /sdcard/backup/apps/ and rename to *.apk
# com.sina.weibo-1/base.apk -> com.sina.weibo-1 -> weibo-1.apk

filelist=`ls */base.apk`
for file in $filelist
do
	tmp=${file%/*}
	#echo ${file}
	tmp=${tmp##*.}
	#echo ${file}
	cp -a ${file} /sdcard/backup/apps/${tmp}.apk
	echo ${tmp}
done


# #：表示从左边算起第一个
# %：表示去掉从右边算起到第一个
# ##：表示从左边算起最后一个
# %%：表示从右边算起最后一个
#${file%*/} or ${file#/*} 无效

# install apk
pm install /sdcard/backup/apps/myrtspclient-1.apk