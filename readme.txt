auth ��ԭ��ֱ�����е� �н����������û�������
��һ����rsatoken�Ŀ���������pin

rsaauth �������������� �û��� ��passcode
��֧�ֵ�һ����rsatoken�����������᷵��ֵҲ���ӡֵ���ɹ�����1��ʧ�ܷ���0


rsaauth��װ��rsa�ͻ��˵�linuxϵͳִ�У���sdconf.rec��sdopts.rec�ŵ�var/ace���棬Ȼ���޸� sdopts.rec�����ip��ַΪ������ַҲ����ִ�С�
 
      ִ�� ��ʽ�� ������ �û��� passcode
      �ɹ�����1��ʧ�ܷ���0

�����ڷ������н�agent��ip����


windows�£�
1��rsa������Ҫ�д˻���ip

2��sdopts.rec��д�˻���ip����CLIENT_IP=AD server ip,���治Ҫ�ӷֺ�
3��sdconf.rec�������C:\Windows\SysWOW64��
4���˻�����rsa���Ӷ˿�5550 5580����ͨ

����Ҫע��dll��securid�Զ�����in C:\Windows\SysWOW64

rsa server7-8���������ͻ���Windows��linux������Ҫ���Ĵ��뼰�⣬ֻ��Ҫ�滻��sdconf.rec(���ip��ַ���˵Ļ�)


������api���Ĺ�������securid��
1���ڷ�����������nodesecret.rec,�������������ɵ�ָ��λ��
agent_nsload -f nodesecret.rec -d /var/ace
��������Ϊ�ڷ������������ļ�ʱ���õ�����













2014.5.12�������ӷ���ֵ

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