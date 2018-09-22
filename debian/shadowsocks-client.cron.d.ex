#
# Regular cron jobs for the shadowsocks-deepin package
#
0 4	* * *	root	[ -x /usr/bin/shadowsocks-deepin_maintenance ] && /usr/bin/shadowsocks-deepin_maintenance
