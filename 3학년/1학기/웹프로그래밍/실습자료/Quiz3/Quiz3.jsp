<%@ page contentType="text/html;charset=euc-kr" %>

<HTML>
<HEAD>
<TITLE> Quiz 3 - ������� </TITLE>
</HEAD>
<BODY>

<%
int Sum = 0;
int Num = 1;

// for���� ����Ͽ� ������ ���� Num��
// 1���� 5�� �����ϸ鼭 50�� �Ǳ� ������ ����
for(;Num < 50; Num+=5      )
{
	// ¦���̸� ����, Ȧ���̸� �����ϰ�
	// ���� ������ ���
	if(Num % 2 == 0) Sum = Sum + Num;
	else Sum = Sum -Num;

}

<%-- ��� ��� -->
out.print("=" + Sum);
%>

</BODY>
</HTML>
