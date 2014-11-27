auth 是原版直接运行的 有交互的输入用户名密码
第一次用rsatoken的可以输入新pin

rsaauth 运行是两个参数 用户名 和passcode
不支持第一次用rsatoken的情况，程序会返回值也会打印值，成功返回1，失败返回0


rsaauth在装有rsa客户端的linux系统执行，或将sdconf.rec及sdopts.rec放到var/ace下面，然后修改 sdopts.rec下面的ip地址为本机地址也可以执行。
 
      执行 格式： 程序名 用户名 passcode
      成功返回1，失败返回0

必须在服务器中将agent的ip加入


windows下：
1、rsa服务器要有此机器ip

2、sdopts.rec填写此机器ip，如CLIENT_IP=AD server ip,后面不要加分号
3、sdconf.rec必须放在C:\Windows\SysWOW64下
4、此机器到rsa主从端口5550 5580必须通

不需要注册dll，securid自动生成in C:\Windows\SysWOW64

rsa server7-8的升级，客户端Windows和linux均不需要更改代码及库，只需要替换下sdconf.rec(如果ip地址变了的话)


可以用api带的工具生成securid，
1、在服务器上下载nodesecret.rec,用如下命令生成到指定位置
agent_nsload -f nodesecret.rec -d /var/ace
输入密码为在服务器上生成文件时设置的密码













2014.5.12更改增加返回值

Return Value: Description

ACM_OK(1):The user successfully authenticated.
ACE_ERR_INVALID_HANDLE(-1):The handle value is invalid.
ACM_ACCESS_DENIED(-2):The user failed authentication.
ACM_NEXT_CODE_REQUIRED(-3):Next tokencode required.
ACM_NEW_PIN_REQUIRED(-4):New PIN required. 
ACE_TOO_MANY_CALLERS(-5):An attempt was made to use a handle while a call
was already in progress. 
ACE_INVALID_ARG(-6):An invalid argument was supplied to the API
function.
0:N/A error