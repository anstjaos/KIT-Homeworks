<%@ page language="java" contentType="text/html;charset=euc-kr" %>

<HTML>
<HEAD>
<TITLE> Quiz 7 - ���� ���� ��� </TITLE>
</HEAD>
<BODY>

<TABLE border=1>
<TR>
	<TD><B> Server Information </B></TD>
    	<TD><B> �� </B></TD>
</TR>

<% 
out.println ("<TR><TD>��������</TD><TD>" +
application.getServerInfo() + "</TD></TR>");

out.println ("<TR><TD>����������</TD><TD>" +
application.getMajorVersion() + "</TD></TR>");

out.println ("<TR><TD>���̳ʹ���</TD><TD>" +
application.getMinorVersion() + "</TD></TR>");

out.println ("<TR><TD>MIME Ÿ��</TD><TD>" +
application.getMimeType("Quiz7.jsp"));

out.println ("<TR><TD>URL ����</TD><TD>" +
application.getResource("/") + "</TD></TR>");

out.println ("<TR><TD>���ð��</TD><TD>" +
application.getRealPath("/") + "</TD></TR>");

out.println ("<TR><TD>���ؽ�Ʈ����</TD><TD>" +
application.getContext("/") + "</TD></TR>");
%>
</TABLE>

</BODY>
</HTML>
