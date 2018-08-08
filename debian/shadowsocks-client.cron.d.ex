#
# Regular cron jobs for the shadowsocks-client package
#
0 4	* * *	root	[ -x /usr/bin/shadowsocks-client_maintenance ] && /usr/bin/shadowsocks-client_maintenance
