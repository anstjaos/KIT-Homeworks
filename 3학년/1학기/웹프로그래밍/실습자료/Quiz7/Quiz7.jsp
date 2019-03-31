<%@ page language="java" contentType="text/html;charset=euc-kr" %>

<HTML>
<HEAD>
<TITLE> Quiz 7 - 서버 정보 출력 </TITLE>
</HEAD>
<BODY>

<TABLE border=1>
<TR>
	<TD><B> Server Information </B></TD>
    	<TD><B> 값 </B></TD>
</TR>

<% 
out.println ("<TR><TD>서버정보</TD><TD>" +
application.getServerInfo() + "</TD></TR>");

out.println ("<TR><TD>메이저버전</TD><TD>" +
application.getMajorVersion() + "</TD></TR>");

out.println ("<TR><TD>마이너버전</TD><TD>" +
application.getMinorVersion() + "</TD></TR>");

out.println ("<TR><TD>MIME 타입</TD><TD>" +
application.getMimeType("Quiz7.jsp"));

out.println ("<TR><TD>URL 정보</TD><TD>" +
application.getResource("/") + "</TD></TR>");

out.println ("<TR><TD>로컬경로</TD><TD>" +
application.getRealPath("/") + "</TD></TR>");

out.println ("<TR><TD>컨텍스트정보</TD><TD>" +
application.getContext("/") + "</TD></TR>");
%>
</TABLE>

</BODY>
</HTML>
